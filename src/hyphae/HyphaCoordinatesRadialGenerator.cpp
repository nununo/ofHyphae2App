//
//  HyphaCoordinatesRadialGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#include "HyphaCoordinatesRadialGenerator.h"

HyphaCoordinatesRadialGenerator::HyphaCoordinatesRadialGenerator(
  shared_ptr<IField> _field, glm::vec2 _center, double _birthAreaRadius, int _numRays, int _total)
: field(_field)
, center(_center)
, birthAreaRadius(_birthAreaRadius)
, rays(generateRays(_numRays))
, total(_total)
{}

vector<HyphaCoordinates> HyphaCoordinatesRadialGenerator::generateRays(int numRays) {
  vector<HyphaCoordinates> v;
  while (numRays > 0) {
    v.push_back(generateRay());
    numRays--;
  }
  return v;
}

HyphaCoordinates HyphaCoordinatesRadialGenerator::generateRay() {
  auto dir = getNewInwardDirection();
  auto pos = center + getNewOffset();
  return {pos, dir};
}

vector<HyphaCoordinates> HyphaCoordinatesRadialGenerator::get() {
  vector<HyphaCoordinates> v;
  if (total > 0) {
    auto ray = rays[ofRandom(rays.size())];
    v.push_back(ray);
    total--;
  }
  return v;
}

glm::vec2 HyphaCoordinatesRadialGenerator::getNewOffset() {
  return glm::rotate(glm::vec2(birthAreaRadius*ofRandom(0,1)),ofRandom(0,360));
}

glm::vec2 HyphaCoordinatesRadialGenerator::getNewInwardDirection() {
  glm::vec2 dir = {0,0};
  do {
    dir = glm::rotate(glm::vec2(1,0), ofRandom(360));
  } while (!field->isInside(center+dir));
  return dir;
}
