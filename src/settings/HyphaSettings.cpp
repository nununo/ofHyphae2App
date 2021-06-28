//
//  HyphaSettings.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "HyphaSettings.h"
#include "Tools.h"

HyphaSettings::HyphaSettings(const SettingsFile& sf)
: color(sf.getColor("rhizopus:hypha:color"))
, speed(sf.getRangeRange("rhizopus:hypha:speed"))
, energySpentToMove(sf.getRangeRange("rhizopus:hypha:energySpentToMove"))
, maxBendAngle(Tools::toRadians(sf.getRange("rhizopus:hypha:maxBendAngleDeg")))
, maxForkAngle(Tools::toRadians(sf.getRange("rhizopus:hypha:maxForkAngleDeg")))
, maxAngleWithInitialDirection(Tools::toRadians(sf.getRange("rhizopus:hypha:maxAngleWithInitialDirection")))
, foodToEnergyRatio(sf.getRange("rhizopus:hypha:foodToEnergyRatio"))
, forkDistance(sf.getRangeRange("rhizopus:hypha:forkDistance"))
, maxGrowthPercentage(sf.getRange("rhizopus:hypha:maxGrowthPercentage"))
, birthRays(sf.getRange("rhizopus:hypha:birthRays"))
, birthRayDirections(sf.getRange("rhizopus:hypha:birthRayDirections"))
, fertilityRatio(sf.getRange("rhizopus:hypha:fertilityRatio"))
, maxElements(sf.getRange("rhizopus:hypha:maxElements"))
, finishLinesBeforeHyphaeDeath(sf.getValue("rhizopus:hypha:finishLinesBeforeHyphaeDeath", 1))
{}
