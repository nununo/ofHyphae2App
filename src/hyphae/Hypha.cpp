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
, energy(HyphaEnergy(initialEnergy, calcEnergySpentToMove(_params->energySpentToMove)))
, nextForkDistance(getNextForkDistance())
{}

/*
 We use a cubed random number so that the lows are much more probable than the highs. Then we map it in
 a way that the higher threshold is more probable than the lower threshold.
 */
double Hypha::calcEnergySpentToMove(glm::vec2 energySpentToMoveInterval) {
  auto r = pow(ofRandom(1.0f), 3);
  return ofMap(r, 0, 1, energySpentToMoveInterval.y, energySpentToMoveInterval.x);
}

bool Hypha::isAlive() const {
  return !dead;
}

bool Hypha::isInside() const {
  return inside;
}

void Hypha::updateDeadStatus() {
  if (energy.isEmpty()) {
    dead = true;
  }
}

void Hypha::updateInsideStatus(IField &field) {
  if (!field.isInside(kynetics.getPixelPos())) {
    inside = false;
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
      updateDeadStatus();
      updateInsideStatus(field);
      moved = isAlive() && isInside();
      if (moved) {
        throwMovedEvent();
      }
    }
  }
  return moved;
}

void Hypha::update(IField &field, const bool allowForks) {
  if (!move(field)) {return;}
  auto food = takeFoodFromField(field);
  energy.eat(food);
  if (allowForks) {
    fork();
  }
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
  if (isInside() && --nextForkDistance == 0) {
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
  auto nextForkDistance = ofMap(0.0f, 0.0f, 1.0f, params->forkDistanceInterval.x, params->forkDistanceInterval.y);
  return nextForkDistance;
}

glm::vec2 Hypha::getPosition() const {
  return kynetics.getPixelPos();
}
