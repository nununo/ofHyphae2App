//
//  HyphaCoordinatesLeftRightGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#include "HyphaCoordinatesLeftRightGenerator.h"

HyphaCoordinatesLeftRightGenerator::HyphaCoordinatesLeftRightGenerator(glm::vec2 _center, int _total)
: center(_center)
, total(_total)
{}

vector<HyphaCoordinates> HyphaCoordinatesLeftRightGenerator::get() {
  vector<HyphaCoordinates> v;
  if (total > 0) {
    auto xdir = center.x <= 0? 1 : -1;
    v.push_back(HyphaCoordinates(center, {xdir, 0}));
    total--;
  }
  return v;
}
