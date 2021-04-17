//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const HyphaParams& _params, const Field& _field, const glm::vec2 _pos, const glm::vec2 _dir, const double initialEnergy)
: field(_field)
, params(_params)
, energy(initialEnergy)
{
  kynetics.reset(new HyphaKynetics(_params, _pos, _dir));
  painter.reset(new Painter(1, ofColor::red));
}

void Hypha::update() {
  if (energy > 0) {
    kynetics->update();
    updateEnergy();
  }
  painter->clear();
  painter->add(kynetics->getPos());
}

void Hypha::throwForkEvent() {
  //HyphaForkEventArgs e(pos, nextForkAngle(dir));
  //ofNotifyEvent(this->forkEvent, e);
}
