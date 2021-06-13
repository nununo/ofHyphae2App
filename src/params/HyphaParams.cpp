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
, energySpentToMove({ Tools::randomInRange(hyphaSettings.energySpentToMove.min), Tools::randomInRange(hyphaSettings.energySpentToMove.max) })
, maxBendAngle(Tools::randomInRange(hyphaSettings.maxBendAngle))
, maxForkAngle(Tools::randomInRange(hyphaSettings.maxForkAngle))
, foodToEnergyRatio(Tools::randomInRange(hyphaSettings.foodToEnergyRatio))
, forkDistanceInterval({ Tools::randomInRange(hyphaSettings.forkDistance.min), Tools::randomInRange(hyphaSettings.forkDistance.max) })
, birthRays(Tools::randomInRange(hyphaSettings.birthRays))
, birthRayDirections(Tools::randomInRange(hyphaSettings.birthRayDirections))
, birthAreaRadius(Tools::randomInRange(hyphaSettings.birthAreaRadius))
, maxGrowthPercentage(Tools::randomInRange(hyphaSettings.maxGrowthPercentage))
, pixelOverlap(hyphaSettings.pixelOverlap)
{}
