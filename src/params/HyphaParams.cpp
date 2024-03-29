//
//  HyphaParams.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "HyphaParams.h"
#include "Tools.h"

HyphaParams::HyphaParams(const HyphaSettings& hyphaSettings)
: speed(Tools::randomInRangeRange(hyphaSettings.speed))
, energySpentToMove(Tools::randomInRangeRange(hyphaSettings.energySpentToMove))
, maxBendAngle(Tools::randomInRange(hyphaSettings.maxBendAngle))
, maxForkAngle(Tools::randomInRange(hyphaSettings.maxForkAngle))
, maxAngleWithInitialDirection(Tools::randomInRange(hyphaSettings.maxAngleWithInitialDirection))
, foodToEnergyRatio(Tools::randomInRange(hyphaSettings.foodToEnergyRatio))
, forkDistanceInterval({ Tools::randomInRange(hyphaSettings.forkDistance.min), Tools::randomInRange(hyphaSettings.forkDistance.max) })
, birthRays(Tools::randomInRange(hyphaSettings.birthRays))
, birthRayDirections(Tools::randomInRange(hyphaSettings.birthRayDirections))
, maxGrowthPercentage(Tools::randomInRange(hyphaSettings.maxGrowthPercentage))
, fertilityRatio(Tools::randomInRange(hyphaSettings.fertilityRatio))
, maxElements(Tools::randomInRange(hyphaSettings.maxElements))
, finishLinesBeforeHyphaeDeath(hyphaSettings.finishLinesBeforeHyphaeDeath)
{}
