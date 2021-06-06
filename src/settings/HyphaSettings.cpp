//
//  HyphaSettings.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "HyphaSettings.h"

HyphaSettings::HyphaSettings(const SettingsFile& sf)
: color(sf.getColor("rhizopus:hypha:color"))
, speed(sf.getRange("rhizopus:hypha:speed"))
, energySpentToMove({sf.getRange("rhizopus:hypha:energySpentToMove:min"), sf.getRange("rhizopus:hypha:energySpentToMove:max")})
, maxBendAngle(glm::radians(sf.getRange("rhizopus:hypha:maxBendAngleDeg")))
, maxForkAngle(glm::radians(sf.getRange("rhizopus:hypha:maxForkAngleDeg")))
, foodToEnergyRatio(sf.getRange("rhizopus:hypha:foodToEnergyRatio"))
, pixelOverlap(sf.getValue("rhizopus:hypha:pixelOverlap", 1.0f))
, forkDistance({sf.getRange("rhizopus:hypha:forkDistance:min"), sf.getRange("rhizopus:hypha:forkDistance:max")})
, maxGrowthPercentage(sf.getRange("rhizopus:hypha:maxGrowthPercentage"))
, birthAreaRadius(sf.getRange("rhizopus:hypha:birthAreaRadius"))
{}
