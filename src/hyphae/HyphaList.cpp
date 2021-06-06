//
//  HyphaList.cpp
//  rhizopusApp
//
//  Created by Nuno on 05/06/2021.
//

#include "HyphaList.h"
#include "HyphaComparator.h"

glm::vec2 HyphaList::getCenterOfMass() const {
  auto p = glm::vec2(0,0);
  for(auto e: *this) {
    p += e.getPosition();
  }
  return p / (double)size();
}

void HyphaList::sortByDistanceToPoint(glm::vec2 point) {
  sort(HyphaComparator(point));
}

double HyphaList::getPercentageThresholdRadius(double percentage) {
  auto centerOfMass = getCenterOfMass();
  sortByDistanceToPoint(centerOfMass);

  auto threshold = (int)(percentage/100.0f * size());
  auto it = begin();
  std::advance(it, threshold-1);
  auto radius = glm::distance(centerOfMass, it->getPosition());
  return radius;
}

double HyphaList::getDensity(double percentage) {
  auto radius = getPercentageThresholdRadius(percentage);
  auto density = size() / radius;
  return density;
}
