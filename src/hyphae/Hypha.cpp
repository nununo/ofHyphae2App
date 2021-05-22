//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(std::shared_ptr<HyphaParams> _params, const HyphaCoordinates _coordinates, const double initialEnergy)
: kynetics(HyphaKynetics(_params, _coordinates))
, params(_params)
, energy(HyphaEnergy(initialEnergy, _params->energySpentToMove))
, nextForkDistance(getNextForkDistance())
{}

bool Hypha::isAlive() const {
  return !dead;
}

void Hypha::updateDeadStatus(IField &field) {
  if (energy.isEmpty() || !kynetics.isInsideField(field.getSize())) {
    dead = true;
  }
}

void Hypha::update(IField &field) {
  if (!isAlive()) {
  return;
  }
  if (!kynetics.update()) {
    return; // update() returns true if moved to new pixel
  }
  updateDeadStatus(field);
  if (!isAlive()) {
    return;
  }
  energy.move();
  energy.eat(takeFoodFromField(field));
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

double Hypha::takeFoodFromField(IField &field) {
  return field.consume(kynetics.getPixelPos(), params->foodAmount) * params->foodToEnergyRatio;
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
 * - Stronger Hypha is potentially more fertile
 * - Use HyphaParams.fertilityRatio
 * - Add a random factor
 */
int Hypha::getNextForkDistance() const {
  auto fertilityRatio = ofRandom(1 - energy.get());
  auto nextForkDistance = ofMap(fertilityRatio, 0.0f, 1.0f, params->forkDistanceInterval.x, params->forkDistanceInterval.y);
  return nextForkDistance;
}
