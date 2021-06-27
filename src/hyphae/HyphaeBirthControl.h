//
//  HyphaeBirthControl.h
//  rhizopusApp
//
//  Created by Nuno on 13/06/2021.
//

#ifndef HyphaeBirthControl_h
#define HyphaeBirthControl_h

#include "LifeDeathCounter.h"

class HyphaeBirthControl {
  const double maxGrowthRatio;
  const double fertilityRatio;
  const int maxElements;
  LifeDeathCounter total;
  LifeDeathCounter latest;
  double currentFertilityRatio;

  double calcCurrentFertilityRatio(const int totalAlive) const;

public:
  HyphaeBirthControl(const double maxGrowthPercentage, const double fertilityRatio, const int maxElements);
  void birth();
  void death();
  void newFrame();
  int getLatestBirths() const;
  int getLatestDeaths() const;
  double getCurrentFertilityRatio() const;
  bool allowFork();
};

#endif /* HyphaeBirthControl_h */
