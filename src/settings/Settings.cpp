//
//  Settings.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Settings.h"

Settings::Settings(const SettingsFile& sf)
: hypha(make_shared<const HyphaSettings>(sf))
, canvas(make_shared<const CanvasSettings>(sf))
, field(make_shared<const FieldSettings>(sf))
{}
