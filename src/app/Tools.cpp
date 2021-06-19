//
//  Tools.cpp
//  hyphaeApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Tools.h"

int Tools::angleToInt(double angle) {
  return ((int)((angle+36000) + 0.5))%360;
}

double Tools::angleTo360(double angle) {
  while(angle>360) {angle-=360;}
  while(angle<0) {angle+=360;}
  return angle;
}

double Tools::randomInSet(vector<double> set) {
  auto r = (int)ofRandom(set.size()-0.1f);
  return set[r];
}

double Tools::posToAngle(glm::vec2 v) {
  return glm::angle(glm::vec2(1,0), v);
}

double Tools::randomInRange(Range r) {
  return ofRandom(r.min, r.max);
}

glm::vec2 Tools::getRandomVec2() {
  return glm::vec2(ofRandom(99999), ofRandom(99999));
}

Range Tools::toRadians(Range degrees) {
  return {
    .min = glm::radians(degrees.min),
    .max = glm::radians(degrees.max)
  };
}
