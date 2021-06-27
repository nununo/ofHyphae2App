//
//  HyphaCoordinatesRadialGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#include "HyphaCoordinatesRadialGenerator.h"

HyphaCoordinatesRadialGenerator::HyphaCoordinatesRadialGenerator(
  const double _maxAngle, const int _numDirections, const int _total)
: maxAngle{_maxAngle}
, total{_total}
, directions{generateDirections(_numDirections)}
{}

vector<HyphaCoordinates> HyphaCoordinatesRadialGenerator::generateDirections(int numDirections) {
  vector<HyphaCoordinates> v;
  while (numDirections > 0) {
    v.push_back(generateDirection());
    numDirections--;
  }
  return v;
}

HyphaCoordinates HyphaCoordinatesRadialGenerator::generateDirection() const {
  return HyphaCoordinates(getNewPosition(), getNewDirection());
}

vector<HyphaCoordinates> HyphaCoordinatesRadialGenerator::get() {
  vector<HyphaCoordinates> v;
  if (total > 0) {
    auto direction = directions[ofRandom(directions.size())];
    v.push_back(direction);
    total--;
  }
  return v;
}

glm::vec2 HyphaCoordinatesRadialGenerator::getNewPosition() const {
  return glm::vec2(0,ofGetScreenHeight()/2); // TODO
}


glm::vec2 HyphaCoordinatesRadialGenerator::getNewDirection() const {
  float angle = ofRandom(maxAngle)-maxAngle/2;
  return glm::rotate(glm::vec2(1,0), angle);
}
