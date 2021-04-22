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
  const double energySpentToMove;
  const double maxBendAngle;
  const double maxForkAngle;
  const double foodAmount;
  const double foodToEnergyRatio;
  const glm::vec2 forkDistanceInterval;
  const double pixelOverlap;

  HyphaParams(const HyphaSettings& hyphaSettings);
};

#endif /* HyphaParams_h */
