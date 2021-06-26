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
, speed(sf.getRange("rhizopus:hypha:speed"))
, energySpentToMove({sf.getRange("rhizopus:hypha:energySpentToMove:min"), sf.getRange("rhizopus:hypha:energySpentToMove:max")})
, maxBendAngle(Tools::toRadians(sf.getRange("rhizopus:hypha:maxBendAngleDeg")))
, maxForkAngle(Tools::toRadians(sf.getRange("rhizopus:hypha:maxForkAngleDeg")))
, maxAngleWithOriginalDirection(Tools::toRadians(sf.getRange("rhizopus:hypha:maxAngleWithOriginalDirection")))
, foodToEnergyRatio(sf.getRange("rhizopus:hypha:foodToEnergyRatio"))
, pixelOverlap(sf.getValue("rhizopus:hypha:pixelOverlap", 1.0f))
, forkDistance({sf.getRange("rhizopus:hypha:forkDistance:min"), sf.getRange("rhizopus:hypha:forkDistance:max")})
, maxGrowthPercentage(sf.getRange("rhizopus:hypha:maxGrowthPercentage"))
, birthRays(sf.getRange("rhizopus:hypha:birthRays"))
, birthRayDirections(sf.getRange("rhizopus:hypha:birthRayDirections"))
, birthAreaRadius(sf.getRange("rhizopus:hypha:birthAreaRadius"))
{}
