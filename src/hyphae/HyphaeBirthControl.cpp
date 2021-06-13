//
//  HyphaeBirthControl.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/06/2021.
//

#include "HyphaeBirthControl.h"
#include "ofMain.h"

HyphaeBirthControl::HyphaeBirthControl(const double _maxGrowthPercentage, const double _maxDensity)
: maxGrowthRatio(_maxGrowthPercentage/100.0f)
, maxDensity(_maxDensity)
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

void HyphaeBirthControl::reset(const double density) {
  fertilityRatio = determineFertilityRatio(total.getDiff(), latest.getDiff(), density);
  latest.reset();
}

int HyphaeBirthControl::getLatestBirths() const {
  return latest.getBirths();
}

int HyphaeBirthControl::getLatestDeaths() const {
  return latest.getDeaths();
}

int HyphaeBirthControl::getMaxBirths(const int totalAlive) const {
  auto maxBirths = totalAlive * maxGrowthRatio;
  return maxBirths>10? maxBirths : 10; // TODO (max births low threshold)
}

double HyphaeBirthControl::determineFertilityRatio(const int totalAlive, const int lastUpdateAlive, const double density) const {
  auto birthAmount = ofMap(lastUpdateAlive, 0, getMaxBirths(totalAlive), 0, 1);
  auto densityAmount = ofMap(density, 0.0f, maxDensity, 0.0f, 1.0f);
  return 1 - max(birthAmount, densityAmount);
}

double HyphaeBirthControl::getFertilityRatio() const {
  return fertilityRatio;
}

bool HyphaeBirthControl::allowFork() {
  return ofRandom(1.0f) <= fertilityRatio;
}
