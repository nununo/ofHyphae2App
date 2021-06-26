//
//  HyphaeBirthControl.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/06/2021.
//

#include "HyphaeBirthControl.h"
#include "ofMain.h"

HyphaeBirthControl::HyphaeBirthControl(const double _maxGrowthPercentage, shared_ptr<IOccupancy> _occupancy)
: maxGrowthRatio{_maxGrowthPercentage/100.0f}
, occupancy{_occupancy}
, fertilityRatio{1.0f}
{}

void HyphaeBirthControl::birth() {
  total.birth();
  latest.birth();
}

void HyphaeBirthControl::death() {
  total.death();
  latest.death();
}

void HyphaeBirthControl::reset() {
  fertilityRatio = determineFertilityRatio(total.getDiff());
  latest.reset();
}

int HyphaeBirthControl::getLatestBirths() const {
  return latest.getBirths();
}

int HyphaeBirthControl::getLatestDeaths() const {
  return latest.getDeaths();
}

double HyphaeBirthControl::determineFertilityRatio(const int totalAlive) const {
  if (totalAlive > 60000) { // TODO
    return 0.0f;
  }
  return pow(totalAlive, 0.9f) / totalAlive; // TODO
}

double HyphaeBirthControl::getFertilityRatio() const {
  return fertilityRatio;
}

bool HyphaeBirthControl::allowFork(const glm::vec2 pos) {
  auto oc = occupancy->getOccupancy(pos);
  auto fertilityRatioAndOccupancy = fertilityRatio * (1 - oc);
  return ofRandom(1.0f) <= fertilityRatioAndOccupancy;
}
