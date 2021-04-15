//
//  Params.h
//  rhizopusApp
//
//  Created by Nuno on 15/04/2021.
//

#ifndef Params_h
#define Params_h

#include "ofMain.h"
#include "Tools.h"
#include "Settings.h"

struct HyphaParams {
  const ofColor color;
  const double speed;
  const double energySpentToMove;
  const double maxBendAngle;
  const double maxForkAngle;
  const double foodAmount;
  const double foodToEnergyRatio;
  
  HyphaParams(const HyphaSettings& hyphaSettings)
  : color(hyphaSettings.color)
  , speed(Tools::randomInRange(hyphaSettings.speed))
  , energySpentToMove(Tools::randomInRange(hyphaSettings.energySpentToMove))
  , maxBendAngle(Tools::randomInRange(hyphaSettings.maxBendAngle))
  , maxForkAngle(Tools::randomInRange(hyphaSettings.maxForkAngle))
  , foodAmount(Tools::randomInRange(hyphaSettings.foodAmount))
  , foodToEnergyRatio(Tools::randomInRange(hyphaSettings.foodToEnergyRatio))
  {}
};

#endif /* Params_h */
