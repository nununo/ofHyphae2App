//
//  HyphaeBirthControl.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/06/2021.
//

#include "HyphaeBirthControl.h"
#include "ofMain.h"

HyphaeBirthControl::HyphaeBirthControl(const double _maxGrowthPercentage)
: maxGrowthRatio(_maxGrowthPercentage/100.0f)
, fertilityRatio(1.0f)
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
  return totalAlive > 40000? 0.0f : pow(totalAlive, 0.75f) / totalAlive; // TODO
}

double HyphaeBirthControl::getFertilityRatio() const {
  return fertilityRatio;
}

bool HyphaeBirthControl::allowFork() {
  return ofRandom(1.0f) <= fertilityRatio;
}
