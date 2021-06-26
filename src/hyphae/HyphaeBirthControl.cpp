//
//  HyphaeBirthControl.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/06/2021.
//

#include "HyphaeBirthControl.h"
#include "ofMain.h"

HyphaeBirthControl::HyphaeBirthControl(const double _maxGrowthPercentage, const double _fertilityRatio, const int _maxElements)
: maxGrowthRatio(_maxGrowthPercentage/100.0f)
, fertilityRatio(_fertilityRatio)
, maxElements(_maxElements)
, currentFertilityRatio(1.0f)
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
  currentFertilityRatio = determineCurrentFertilityRatio(total.getDiff());
  latest.reset();
}

int HyphaeBirthControl::getLatestBirths() const {
  return latest.getBirths();
}

int HyphaeBirthControl::getLatestDeaths() const {
  return latest.getDeaths();
}

double HyphaeBirthControl::determineCurrentFertilityRatio(const int totalAlive) const {
  return totalAlive > maxElements? 0.0f : pow(totalAlive, fertilityRatio) / totalAlive; // TODO
}

double HyphaeBirthControl::getCurrentFertilityRatio() const {
  return currentFertilityRatio;
}

bool HyphaeBirthControl::allowFork() {
  return ofRandom(1.0f) <= currentFertilityRatio;
}
