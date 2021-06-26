//
//  HyphaeBirthControl.h
//  rhizopusApp
//
//  Created by Nuno on 13/06/2021.
//

#ifndef HyphaeBirthControl_h
#define HyphaeBirthControl_h

#include "LifeDeathCounter.h"
#include "IOccupancy.h"

class HyphaeBirthControl {
  const double maxGrowthRatio;
  LifeDeathCounter total;
  LifeDeathCounter latest;
  double fertilityRatio;
  shared_ptr<IOccupancy> occupancy;

  double determineFertilityRatio(const int totalAlive) const;

public:
  HyphaeBirthControl(const double maxGrowthPercentage, shared_ptr<IOccupancy> occupancy);
  void birth();
  void death();
  void reset();
  int getLatestBirths() const;
  int getLatestDeaths() const;
  double getFertilityRatio() const;
  bool allowFork(const glm::vec2 pos);
};

#endif /* HyphaeBirthControl_h */
