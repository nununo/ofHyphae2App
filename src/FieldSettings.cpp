//
//  FieldSettings.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "FieldSettings.h"

FieldSettings::FieldSettings(const SettingsFile& sf)
: zeroThreshold(sf.getRange("rhizopus:field:zeroThreshold", 0.5f))
{}
