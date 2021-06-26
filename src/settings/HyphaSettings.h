//
//  HyphaSettings.h
//  rhizopusApp
//
//  Created by Nuno on 15/04/2021.
//

#ifndef HyphaSettings_h
#define HyphaSettings_h

#include "SettingsFile.h"
#include "RangeRange.h"

class HyphaSettings {
public:
  const ofColor color;
  const RangeRange speed;
  const RangeRange energySpentToMove;
  const Range maxBendAngle;
  const Range maxForkAngle;
  const Range maxAngleWithInitialDirection;
  const Range foodToEnergyRatio;
  const RangeRange forkDistance;
  const Range birthRayDirections;
  const Range birthRays;
  const Range birthAreaRadius;
  const Range maxGrowthPercentage;

  HyphaSettings(const SettingsFile& sf);
};

#endif /* HyphaSettings_h */
