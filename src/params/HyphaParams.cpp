//
//  HyphaParams.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "HyphaParams.h"
#include "Tools.h"

HyphaParams::HyphaParams(const HyphaSettings& hyphaSettings)
: color(hyphaSettings.color)
, speed(Tools::randomInRange(hyphaSettings.speed))
, energySpentToMove(Tools::randomInRange(hyphaSettings.energySpentToMove))
, maxBendAngle(Tools::randomInRange(hyphaSettings.maxBendAngle))
, maxForkAngle(Tools::randomInRange(hyphaSettings.maxForkAngle))
, foodAmount(Tools::randomInRange(hyphaSettings.foodAmount))
, foodToEnergyRatio(Tools::randomInRange(hyphaSettings.foodToEnergyRatio))
{}
