//
//  Settings.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Settings.h"

Settings::Settings(const SettingsFile& sf)
: hypha(HyphaSettings(sf))
, canvas(CanvasSettings(sf))
, field(FieldSettings(sf))
{}
