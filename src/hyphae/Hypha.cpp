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
             const double initialEnergy,
             const HyphaStatus _status = HyphaStatus::BeforeInside)
: kynetics{HyphaKynetics(_params, _coordinates)}
, params{_params}
, energy{HyphaEnergy(initialEnergy, _params->energySpentToMove)}
, nextForkDistance{getNextForkDistance()}
, status(_status)
{}

bool Hypha::isAlive() const {
  return status != HyphaStatus::Dead;
}

/*
 It can start outside and then go inside. Fine. But once it has been inside,
 if it goes outside... it dies.
 */
HyphaStatus Hypha::calcStatus(IField &field, HyphaStatus oldStatus) const {
  if (energy.isEmpty() || kynetics.angleWithOriginalDirection() >= 100) { // TODO
    return HyphaStatus::Dead;
  }
  
  auto inside = field.isInside(kynetics.getPixelPos());
  
  if (inside && oldStatus == HyphaStatus::BeforeInside) {
    return HyphaStatus::Inside;
  }
  
  if (!inside && oldStatus == HyphaStatus::Inside) {
    return HyphaStatus::Dead;
  }
  
  return oldStatus;
}

double Hypha::getSpeed() const {
  return params->speed * ofMap(energy.get(), 0, 1, 0.9f, 1.0f); // TODO
}

bool Hypha::move(IField &field) {
  if (!isAlive()) {
    return false;
  }

  bool moved =false;
  if (kynetics.update(getSpeed())) {
    energy.move();
    status = calcStatus(field, status);
    moved = isAlive();
  }
  return moved;
}

bool Hypha::update(IField &field, const bool allowForks) {
  if (move(field)) {
    auto food = takeFoodFromField(field);
    energy.eat(food);
    if (allowForks && status != HyphaStatus::Dead) {
      fork();
    }
    // If it moved and is still inside, return true (to be added to Hyphae newPositions)
    return status == HyphaStatus::Inside;
  } else {
    return false;
  }
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e(kynetics.getForkCoordinates(), energy.get(), status);
  ofNotifyEvent(this->forkEvent, e);
}

double Hypha::takeFoodFromField(IField &field) {
  return status == HyphaStatus::Inside ? field.getValue(kynetics.getPixelPos()) * params->foodToEnergyRatio : 1.0f;
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
  auto nextForkDistance = ofMap(0.0f, 0.0f, 1.0f, params->forkDistanceInterval.min, params->forkDistanceInterval.max);
  return nextForkDistance;
}

glm::vec2 Hypha::getPosition() const {
  return kynetics.getPixelPos();
}
