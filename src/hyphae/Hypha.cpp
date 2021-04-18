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

HyphaKynetics Hypha::getKynetics() const {
  return kynetics;
}

bool Hypha::isAlive() const {
  return energy>0;
}

void Hypha::update() {
  if (energy > 0) {
    kynetics.update();
    updateEnergy();
    //fork();
  }
}

void Hypha::updateEnergy() {
  auto eaten = eat();
  energy = energy - params.energySpentToMove + eaten;
  ofLog() << "pos: " << kynetics.getPos() << " energy: " << energy << " spent: " << params.energySpentToMove << " eaten: " << eaten;
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e(kynetics.getForkKynetics());
  ofNotifyEvent(this->forkEvent, e);
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
