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

void Hypha::throwForkEvent() {
  //HyphaForkEventArgs e(pos, nextForkAngle(dir));
  //ofNotifyEvent(this->forkEvent, e);
}

void Hypha::paint(Painter *painter) {
  painter->add(kynetics.getPos());
}
