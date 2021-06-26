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
  const ofColor color;
  const double speed;
  const Range energySpentToMove;
  const double maxBendAngle;
  const double maxForkAngle;
  const double maxAngleWithOriginalDirection;
  const double foodToEnergyRatio;
  const Range forkDistanceInterval;
  const int birthRays;
  const int birthRayDirections;
  const double birthAreaRadius;
  const double pixelOverlap;
  const double maxGrowthPercentage;

  HyphaParams(const HyphaSettings& hyphaSettings);
};

#endif /* HyphaParams_h */
