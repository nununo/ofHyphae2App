//
//  HyphaKinetics.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "HyphaKynetics.h"

long HyphaKynetics::counter = 0;

HyphaKynetics::HyphaKynetics(shared_ptr<const HyphaParams> _params, const HyphaCoordinates _coordinates)
: params(_params)
, coordinates(_coordinates)
{
  updateAngleWithOriginalDirection();
}

glm::vec2 HyphaKynetics::getPixelPos() const {
  return {glm::floor(coordinates.pos.x), glm::floor(coordinates.pos.y)};
}

glm::vec2 HyphaKynetics::nextDirection(const glm::vec2 dir) const {
  return glm::rotate(dir, ofRandom(-params->maxBendAngle, params->maxBendAngle));
}

bool HyphaKynetics::update(double speed) {
  if (counter++ % 10 == 0) {
    updateAngleWithOriginalDirection();
  }
  coordinates.pos += coordinates.dir * speed;
  auto pixelPos = getPixelPos();
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
