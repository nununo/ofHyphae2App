//
//  HyphaKinetics.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "HyphaKynetics.h"

HyphaKynetics::HyphaKynetics(shared_ptr<const HyphaParams> _params, const HyphaCoordinates _coordinates)
: params(_params)
, coordinates(_coordinates)
{
  updateAngleWithOriginalDirection();
}

glm::vec2 HyphaKynetics::getPixelPos() const {
  return lastPixelPos;
}

glm::vec2 HyphaKynetics::nextDirection(const glm::vec2 dir) const {
  return glm::rotate(dir, ofRandom(-params->maxBendAngle, params->maxBendAngle));
}

bool HyphaKynetics::update(double speed) {
  if (cacheLifetime-- <= 0) {
    // This is expensive so we do it every 10 updates only
    updateAngleWithOriginalDirection();
    cacheLifetime = 10;
  }
  coordinates.pos += coordinates.dir * speed;
  auto pixelPos = glm::vec2{glm::floor(coordinates.pos.x), glm::floor(coordinates.pos.y)};
  if (pixelPos != lastPixelPos) {
    coordinates.dir = nextDirection(coordinates.dir);
    lastPixelPos = pixelPos;
    return true;
  } else {
    return false;
  }
}

HyphaCoordinates HyphaKynetics::getForkCoordinates() {
  auto forkCoordinates = coordinates;
  forkCoordinates.dir = nextDirection(coordinates.dir);
  return forkCoordinates;
}

void HyphaKynetics::updateAngleWithOriginalDirection() {
  cachedAngleWithOriginaDirection = glm::degrees(glm::abs(glm::orientedAngle(coordinates.dir, coordinates.originalDir)));
}

double HyphaKynetics::angleWithOriginalDirection() const {
  return cachedAngleWithOriginaDirection;
}
