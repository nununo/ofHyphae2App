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
    auto ray = HyphaCoordinates(center, {xdir, 0});
    ofLog() << "ray: " << ray;
    v.push_back(ray);
    total--;
  }
  return v;
}
