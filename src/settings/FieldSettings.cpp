//
//  FieldSettings.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "FieldSettings.h"

FieldSettings::FieldSettings(const SettingsFile& sf)
: frequency(sf.getRange("rhizopus:field:frequency"))
, amplification(sf.getRange("rhizopus:field:amplification"))
{}
