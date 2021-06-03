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
  if (energy.isEmpty() || !field.isInside(kynetics.getPixelPos())) {
    dead = true;
  }
}

double Hypha::getSpeed() const {
  return params->speed * ofMap(energy.get(), 0, 1, 0.5f, 1.0f); // TODO
}

bool Hypha::move(IField &field) {
  bool moved =false;
  if (isAlive()) {
    if (kynetics.update(getSpeed())) {
      energy.move();
      updateDeadStatus(field);
      moved = isAlive();
      if (moved) {
        throwMovedEvent();
      }
    }
  }
  return moved;
}

void Hypha::update(IField &field) {
  if (!move(field)) {return;}
  auto food = takeFoodFromField(field);
  energy.eat(food);
  fork();
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
  return field.getValue(kynetics.getPixelPos()) * params->foodToEnergyRatio;
}

void Hypha::fork() {
  if (--nextForkDistance == 0) {
    energy.fork();
    throwForkEvent();
    nextForkDistance = getNextForkDistance();
  }
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
