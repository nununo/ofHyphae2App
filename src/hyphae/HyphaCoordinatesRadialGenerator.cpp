//
//  HyphaCoordinatesRadialGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#include "HyphaCoordinatesRadialGenerator.h"

HyphaCoordinatesRadialGenerator::HyphaCoordinatesRadialGenerator(glm::vec2 _pos, int _numRays)
: pos(_pos)
, numRays(_numRays)
{}

vector<HyphaCoordinates> HyphaCoordinatesRadialGenerator::get() {
  vector<HyphaCoordinates> v;
  if (numRays > 0) {
    HyphaCoordinates hc = {pos, glm::rotate(glm::vec2(1,0), ofRandom(360))};
    v.push_back(hc);
    numRays--;
  }
  return v;
}
