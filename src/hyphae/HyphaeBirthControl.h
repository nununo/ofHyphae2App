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
  const int maxDensity;
  LifeDeathCounter total;
  LifeDeathCounter latest;
  double fertilityRatio;

  int getMaxBirths(const int totalAlive) const;
  double determineFertilityRatio(const int totalAlive, const int lastUpdateAlive, const double density) const;

public:
  HyphaeBirthControl(const double maxGrowthPercentage, const double maxDensity);
  void birth();
  void death();
  void reset(const double density);
  int getLatestBirths() const;
  int getLatestDeaths() const;
  double getFertilityRatio() const;
  bool allowFork();
};

#endif /* HyphaeBirthControl_h */
