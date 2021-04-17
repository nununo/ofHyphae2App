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
{}

void Hypha::update() {
  if (energy > 0) {
    kynetics.update();
    updateEnergy();
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
