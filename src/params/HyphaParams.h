//
//  HyphaParams.h
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#ifndef HyphaParams_h
#define HyphaParams_h

#include "ofMain.h"
#include "HyphaSettings.h"

class HyphaParams {
public:
  const Range speed;
  const Range energySpentToMove;
  const double maxBendAngle;
  const double maxForkAngle;
  const double maxAngleWithInitialDirection;
  const double foodToEnergyRatio;
  const Range forkDistanceInterval;
  const int birthRays;
  const int birthRayDirections;
  const double maxGrowthPercentage;
  const double fertilityRatio;
  const int maxElements;
  const int finishLinesBeforeHyphaeDeath;

  HyphaParams(const HyphaSettings& hyphaSettings);
};

#endif /* HyphaParams_h */
