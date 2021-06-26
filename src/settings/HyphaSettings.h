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
  const Range speed;
  const RangeRange energySpentToMove;
  const Range maxBendAngle;
  const Range maxForkAngle;
  const Range maxAngleWithOriginalDirection;
  const Range foodToEnergyRatio;
  const RangeRange forkDistance;
  const Range birthRayDirections;
  const Range birthRays;
  const Range birthAreaRadius;
  const Range maxGrowthPercentage;
  const double pixelOverlap;

  HyphaSettings(const SettingsFile& sf);
};

#endif /* HyphaSettings_h */
