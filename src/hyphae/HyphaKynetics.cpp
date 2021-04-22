//
//  HyphaKinetics.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "HyphaKynetics.h"

HyphaKynetics::HyphaKynetics(const HyphaParams& _params, const HyphaCoordinates _coordinates, const glm::vec2 _fieldSize)
: params(_params)
, fieldSize(_fieldSize)
, coordinates(_coordinates)
{}

glm::vec2 HyphaKynetics::getPos() const {
  return {glm::floor(coordinates.pos.x), glm::floor(coordinates.pos.y)};
}

glm::vec2 HyphaKynetics::nextDirection(const glm::vec2 _dir) const {
  return glm::rotate(_dir, ofRandom(-params.maxBendAngle, params.maxBendAngle));
  
}

bool HyphaKynetics::update() {
  coordinates.pos += coordinates.dir * params.speed;
  auto pixelPos = getPos();
  if (pixelPos != lastPixelPos) {
    coordinates.dir = nextDirection(coordinates.dir);
    lastPixelPos = pixelPos;
    return true;
  } else {
    return false;
  }
}

bool HyphaKynetics::isInsideField() {
  return coordinates.pos == glm::abs(coordinates.pos)
      && coordinates.pos.x < fieldSize.x
      && coordinates.pos.y < fieldSize.y;
}

HyphaCoordinates HyphaKynetics::getForkCoordinates() {
  auto newDirection = glm::rotate(coordinates.dir, ofRandom(-params.maxForkAngle, params.maxForkAngle));
  return {coordinates.pos, newDirection};
}
