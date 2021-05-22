//
//  HyphaCoordinatesRadialGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#include "HyphaCoordinatesRadialGenerator.h"

HyphaCoordinatesRadialGenerator::HyphaCoordinatesRadialGenerator(shared_ptr<IField> _field, glm::vec2 _pos, int _numRays)
: field(_field)
, pos(_pos)
, numRays(_numRays)
{}

vector<HyphaCoordinates> HyphaCoordinatesRadialGenerator::get() {
  vector<HyphaCoordinates> v;
  if (numRays > 0) {
    HyphaCoordinates hc = {pos, getNewDirection()};
    v.push_back(hc);
    numRays--;
  }
  return v;
}

glm::vec2 HyphaCoordinatesRadialGenerator::getNewDirection() {
  glm::vec2 dir = {0,0};
  do {
    dir = glm::rotate(glm::vec2(1,0), ofRandom(360));
  } while (!field->isInside(pos+dir));
  return dir;
}
