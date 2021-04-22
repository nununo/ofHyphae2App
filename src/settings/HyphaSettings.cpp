//
//  HyphaSettings.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "HyphaSettings.h"

HyphaSettings::HyphaSettings(const SettingsFile& sf)
: color(sf.getColor("rhizopus:hypha:color"))
, speed(sf.getRange("rhizopus:hypha:speed", 4.0f))
, energySpentToMove(sf.getRange("rhizopus:hypha:energySpentToMove", 1.0f))
, maxBendAngle(glm::radians(sf.getRange("rhizopus:hypha:maxBendAngleDeg", 1.0f)))
, maxForkAngle(glm::radians(sf.getRange("rhizopus:hypha:maxForkAngleDeg", 1.0f)))
, foodAmount(sf.getRange("rhizopus:hypha:foodAmount", 1.0f))
, eatSpendRatio(sf.getRange("rhizopus:hypha:eatSpendRatio", 1.0f))
, pixelOverlap(sf.getValue("rhizopus:hypha:pixelOverlap", 1.0f))
, forkDistanceMin(sf.getRange("rhizopus:hypha:forkDistanceMin", .05f))
, forkDistanceMax(sf.getRange("rhizopus:hypha:forkDistanceMax", .05f))
{}
