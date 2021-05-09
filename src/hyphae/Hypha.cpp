//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const HyphaParams& _params, std::shared_ptr<IField> _field, const HyphaCoordinates _coordinates, const double initialEnergy)
: field(_field)
, kynetics(HyphaKynetics(_params, _coordinates, _field->getSize()))
, params(_params)
, energy(HyphaEnergy(initialEnergy, _params.energySpentToMove))
, nextForkDistance(getNextForkDistance())
{}

bool Hypha::isAlive() const {
  return !dead;
}

void Hypha::updateDeadStatus() {
  if (energy.isEmpty() || !kynetics.isInsideField()) {
    dead = true;
  }
}

void Hypha::update() {
  if (!isAlive()) {
  return;
  }
  if (!kynetics.update()) {
    return; // update() returns true if moved to new pixel
  }
  updateDeadStatus();
  if (!isAlive()) {
    return;
  }
  energy.move();
  energy.eat(takeFoodFromField());
  if (--nextForkDistance == 0) {
    fork();
  }
  throwMovedEvent();
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e(kynetics.getForkCoordinates(), energy.get());
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::throwMovedEvent() {
  HyphaMovedEventArgs e(kynetics.getPixelPos());
  ofNotifyEvent(this->movedEvent, e);
}

double Hypha::takeFoodFromField() {
  return field->consume(kynetics.getPixelPos(), params.foodAmount) * params.foodToEnergyRatio;
}

void Hypha::fork() {
  energy.fork();
  throwForkEvent();
  nextForkDistance = getNextForkDistance();
}

/**
 * Determine distance to next fork
 *
 * Criteria
 * - Stronger Hypha is more fertile
 * - Use HyphaParams.fertilityRatio
 * - Add a random factor
 */
int Hypha::getNextForkDistance() const {
  auto fertilityRatio = 1 - energy.get();
  auto nextForkDistance = ofMap(fertilityRatio, 0.0f, 1.0f, params.forkDistanceInterval.x, params.forkDistanceInterval.y);
  //ofLog() << "energy: " << energy << " fr: " << fertilityRatio << " dist: " << nextForkDistance;
  return nextForkDistance;
}
