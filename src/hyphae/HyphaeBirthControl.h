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
  LifeDeathCounter total;
  LifeDeathCounter latest;
  double fertilityRatio;

  double determineFertilityRatio(const int totalAlive) const;

public:
  HyphaeBirthControl(const double maxGrowthPercentage);
  void birth();
  void death();
  void reset();
  int getLatestBirths() const;
  int getLatestDeaths() const;
  double getFertilityRatio() const;
  bool allowFork();
};

#endif /* HyphaeBirthControl_h */
