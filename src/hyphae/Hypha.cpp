//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(std::shared_ptr<const
             HyphaParams> _params,
             const HyphaCoordinates _coordinates,
             const double initialEnergy)
: kynetics{HyphaKynetics(_params, _coordinates)}
, params{_params}
, energy{HyphaEnergy(initialEnergy, _params->energySpentToMove)}
, nextForkDistance{getNextForkDistance()}
{}

bool Hypha::isAlive() const {
  return !dead;
}

bool Hypha::calcDead(const IField &field) const {
  return (energy.isEmpty() ||
          kynetics.angleWithOriginalDirection() >= params->maxAngleWithInitialDirection ||
          !field.isInside(kynetics.getPixelPos()));
}

double Hypha::getSpeed() const {
  return ofMap(energy.get(), 0, 1, params->speed.min, params->speed.max);
}

bool Hypha::move(const IField &field) {
  if (!isAlive()) {
    return false;
  }
  bool moved =false;
  if (kynetics.update(getSpeed())) {
    energy.move();
    dead = calcDead(field);
    moved = isAlive();
  }
  return moved;
}

bool Hypha::update(const IField &field) {
  if (move(field)) {
    auto food = takeFoodFromField(field);
    energy.eat(food);
    return true;
  } else {
    return false;
  }
}

double Hypha::takeFoodFromField(const IField &field) {
  return field.getValue(kynetics.getPixelPos()) * params->foodToEnergyRatio;
}

HyphaForkData Hypha::fork() {
  if (isAlive()) {
    if (--nextForkDistance == 0) {
      energy.fork();
      nextForkDistance = getNextForkDistance();
      return HyphaForkData(kynetics.getForkCoordinates(), energy.get());
    }
  }
  return HyphaForkData({{0,0},{0,0}}, 0);
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
  auto nextForkDistance = ofMap(0.0f, 0.0f, 1.0f, params->forkDistanceInterval.min, params->forkDistanceInterval.max);
  return nextForkDistance;
}

glm::vec2 Hypha::getPosition() const {
  return kynetics.getPixelPos();
}
