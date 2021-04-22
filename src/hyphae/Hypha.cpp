//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const HyphaParams& _params, Field *_field, const HyphaCoordinates _coordinates, const double initialEnergy)
: field(_field)
, kynetics(HyphaKynetics(_params, _coordinates, {_field->getWidth(), _field->getHeight()}))
, params(_params)
, energy(initialEnergy)
, nextForkDistance(getNextForkDistance())
{}

bool Hypha::isAlive() const {
  return !dead;
}

void Hypha::updateDeadStatus() {
  if (energy<=0 || !kynetics.isInsideField()) {
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
  updateEnergy();
  if (--nextForkDistance == 0) {
    fork();
  }
  throwMovedEvent();
}

void Hypha::updateEnergy() {
  auto eaten = eat();
  energy = ofClamp(energy - params.energySpentToMove + eaten, 0.0f, 1.0f);
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e(kynetics.getForkCoordinates());
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::throwMovedEvent() {
  HyphaForkEventArgs e(kynetics.getForkCoordinates());
  ofNotifyEvent(this->movedEvent, e);
}

double Hypha::eat() {
  return field->consume(kynetics.getPos(), params.foodAmount) * params.foodToEnergyRatio;
}

void Hypha::fork() {
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
  auto fertilityRatio = 1 - energy;
  auto nextForkDistance = ofMap(fertilityRatio, 0.0f, 1.0f, params.forkDistanceInterval.x, params.forkDistanceInterval.y);
  //ofLog() << "energy: " << energy << " fr: " << fertilityRatio << " dist: " << nextForkDistance;
  return nextForkDistance;
}
