//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const HyphaParams _params, const Field& _field, const glm::vec2 _pos, const glm::vec2 _dir, const float initialEnergy)
: field(_field)
, params(_params)
, pos(_pos)
, dir(_dir * params.speed)
, energy(initialEnergy)
{
  painter.reset(new Painter(1, ofColor::red));
}

void Hypha::update() {
  if (energy > 0) {
  dir = nextDirection(dir);
  pos = nextPosition(pos, dir);
  energy = nextEnergy(energy);
  ofLog() << energy;
  }
  painter->clear();
  painter->add(pos);
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e(pos, nextForkAngle(dir));
  ofNotifyEvent(this->forkEvent, e);
}

