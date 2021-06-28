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

void HyphaeBirthControl::newFrame() {
  currentFertilityRatio = calcCurrentFertilityRatio(total.getDiff());
  latest.reset();
}

int HyphaeBirthControl::getLatestBirths() const {
  return latest.getBirths();
}

int HyphaeBirthControl::getLatestDeaths() const {
  return latest.getDeaths();
}

/**
 AsciiMath current fertility ratio formula: (alive^(fertilityRatio))/(alive) * (maxElements-alive)/maxElements
 In which:
  - alive: num of current particles
  - max: maximum num of particles in this Hyphae
  - fertilityRatio: a parameter (usually <1) obtained from a range in the settings file
 */
double HyphaeBirthControl::calcCurrentFertilityRatio(const int alive) const {
  double f = (pow(alive, fertilityRatio)/(double)alive) * ((maxElements - alive) / (double)maxElements);
  return f>0? f : 0;
}

double HyphaeBirthControl::getCurrentFertilityRatio() const {
  return currentFertilityRatio;
}

bool HyphaeBirthControl::allowFork() {
  return ofRandom(1.0f) <= currentFertilityRatio;
}
