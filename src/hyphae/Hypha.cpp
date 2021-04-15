//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const HyphaParams _params, const Field *_field, const glm::vec2 _pos, const glm::vec2 _dir, const float initialEnergy)
: field(_field)
, params(_params)
, pos(_pos)
, dir(_dir * params.speed)
, energy(initialEnergy)
{
  painter.reset(new Painter(1, ofColor::red));
}

void Hypha::update() {
  dir = nextDirection(dir);
  pos = nextPosition(pos, dir);
  painter->clear();
  painter->add(pos);
}

glm::vec2 Hypha::nextDirection(glm::vec2 dir) const {
  auto bendAngle = ofRandom(-params.maxBendAngle, params.maxBendAngle);
  ofLog() << bendAngle;
  return glm::rotate(dir, bendAngle);
}
