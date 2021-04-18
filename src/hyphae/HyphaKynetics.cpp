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

glm::vec2 HyphaKynetics::getPos() const {
  return {glm::floor(pos.x), glm::floor(pos.y)};
}

glm::vec2 HyphaKynetics::nextDirection(const glm::vec2 _dir) const {
  return glm::rotate(_dir, ofRandom(-params.maxBendAngle, params.maxBendAngle));
  
}

bool HyphaKynetics::update() {
  pos += dir;
  auto pixelPos = getPos();
  if (pixelPos != lastPixelPos) {
    dir = nextDirection(dir);
    lastPixelPos = pixelPos;
    return true;
  } else {
    return false;
  }
}

HyphaKynetics HyphaKynetics::getForkKynetics() {
  auto newDirection = glm::rotate(dir, ofRandom(-params.maxForkAngle, params.maxForkAngle));
  return HyphaKynetics(params, pos, glm::normalize(newDirection));
}
