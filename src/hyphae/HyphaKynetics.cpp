//
//  HyphaKinetics.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "HyphaKynetics.h"

HyphaKynetics::HyphaKynetics(const HyphaParams& _params, const glm::vec2 _pos, const glm::vec2 _dir):
  params(_params),
  pos(_pos),
  dir(_dir * _params.speed)
{}

glm::vec2 HyphaKynetics::nextDirection(const glm::vec2 _dir) const {
  return glm::rotate(_dir, ofRandom(-params.maxBendAngle, params.maxBendAngle));
  
}

void HyphaKynetics::update() {
  delta += dir;
  auto absDeltaX = abs(delta.x);
  auto absDeltaY = abs(delta.y);
  if (absDeltaX>params.pixelOverlap || absDeltaY>params.pixelOverlap) {
    pos += delta;
    dir = nextDirection(dir);
    posIsNewPixel = true;

    if (absDeltaX>0) {delta.x=0;}
    if (absDeltaY>0) {delta.y=0;}
  }
}

HyphaKynetics HyphaKynetics::getForkKynetics() {
  auto newDirection = glm::rotate(dir, ofRandom(-params.maxForkAngle, params.maxForkAngle));
  return HyphaKynetics(params, pos, glm::normalize(newDirection));
}
