//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const HyphaParams& _params, const Field& _field, const HyphaKynetics& _kynetics, const double initialEnergy)
: field(_field)
, kynetics(_kynetics)
, params(_params)
, energy(initialEnergy)
, nextForkDistance(getNextForkDistance())
{}

bool Hypha::isAlive() const {
  return energy>0;
}

void Hypha::update() {
  if (energy > 0) {
    kynetics.update();
    updateEnergy();
    fork();
  }
}

void Hypha::updateEnergy() {
  energy = energy - params.energySpentToMove + eat();
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e(kynetics.getForkKynetics());
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::draw(Painter& painter) {
  painter.add(kynetics.getPos());
}

double Hypha::eat() {
  return field.consume(kynetics.getPos(), params.foodAmount) * params.foodToEnergyRatio;
}

void Hypha::fork() {
  if (--nextForkDistance == 0) {
    throwForkEvent();
    nextForkDistance = getNextForkDistance();
  }
}

int Hypha::getNextForkDistance() const {
  return 20;
}
