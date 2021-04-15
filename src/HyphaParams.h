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
  
  HyphaParams(const HyphaSettings& hyphaSettings)
  : color(hyphaSettings.color)
  , speed(Tools::randomInRange(hyphaSettings.speed))
  , energySpentToMove(Tools::randomInRange(hyphaSettings.energySpentToMove))
  , maxBendAngle(glm::radians(Tools::randomInRange(hyphaSettings.maxBendAngleDeg)))
  {ofLog() << "speed: " << speed;}
};

#endif /* Params_h */
