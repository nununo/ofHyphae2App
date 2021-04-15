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
  const float speed;
  const float energySpentToMove;
  const float maxBendAngle;
  const float maxForkAngle;
  
  HyphaParams(const HyphaSettings& hyphaSettings)
  : color(hyphaSettings.color)
  , speed(Tools::randomInRange(hyphaSettings.speed))
  , energySpentToMove(Tools::randomInRange(hyphaSettings.energySpentToMove))
  , maxBendAngle(Tools::randomInRange(hyphaSettings.maxBendAngle))
  , maxForkAngle(Tools::randomInRange(hyphaSettings.maxForkAngle))
  {ofLog() << "speed: " << speed;}
};

#endif /* Params_h */
