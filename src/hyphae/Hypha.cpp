//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const HyphaParams& _params, Field *_field, const HyphaKynetics& _kynetics, const double initialEnergy)
: field(_field)
, kynetics(_kynetics)
, params(_params)
, energy(initialEnergy)
, nextForkDistance(getNextForkDistance())
{}

HyphaKynetics Hypha::getKynetics() const {
  return kynetics;
}

bool Hypha::isAlive() const {
  return energy>0;
}

void Hypha::update() {
  if (isAlive()) {
    auto hasMoved = kynetics.update();
    updateEnergy();
    fork();
    if (isAlive() && hasMoved) {
      throwMovedEvent();
    }
  }
}

void Hypha::updateEnergy() {
  auto eaten = eat();
  energy = ofClamp(energy - params.energySpentToMove + eaten, 0.0f, 1.0f);
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e(kynetics.getForkKynetics());
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::throwMovedEvent() {
  HyphaForkEventArgs e(kynetics.getForkKynetics());
  ofNotifyEvent(this->movedEvent, e);
}

double Hypha::eat() {
  return field->consume(kynetics.getPos(), params.foodAmount) * params.foodToEnergyRatio;
}

void Hypha::fork() {
  if (--nextForkDistance == 0) {
    throwForkEvent();
    nextForkDistance = getNextForkDistance();
  }
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
  ofLog() << "energy: " << energy << " fr: " << fertilityRatio << " dist: " << nextForkDistance;
  return nextForkDistance;
}
