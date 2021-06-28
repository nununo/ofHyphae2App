//
//  CanvasSettings.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "CanvasSettings.h"

CanvasSettings::CanvasSettings(const SettingsFile& sf)
: framerate(sf.getValue("rhizopus:canvas:framerate", 1)) // 120
, osdColor(sf.getColor("rhizopus:canvas:osdColor"))
, osdActive((bool)sf.getValue("rhizopus:canvas:osdActive", false))
, backgroundColor(sf.getColor("rhizopus:canvas:backgroundColor"))
, saveImages((bool)sf.getValue("rhizopus:canvas:saveImages", true))
{}
