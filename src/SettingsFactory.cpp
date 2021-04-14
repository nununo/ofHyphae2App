//
//  SettingsFactory.cpp
//  rhizopusApp
//
//  Created by Nuno on 14/04/2021.
//

#include "SettingsFactory.h"

Settings* SettingsFactory::getInstance(const string& xmlFilename) {
  SettingsFile sf(xmlFilename);
  return new Settings(buildHyphaSettings(sf), buildCanvasSettings(sf));
}

HyphaSettings SettingsFactory::buildHyphaSettings(const SettingsFile& sf) {
  return {
    .color = sf.getColor("rhizopus:hyphae:hypha:color"),
    .speed = sf.getValue("rhizopus:hyphae:hypha:speed", 1.0f) // / canvas.framerate; // pixels/second
  };
}

CanvasSettings SettingsFactory::buildCanvasSettings(const SettingsFile& sf) {
  return {
    .framerate = sf.getValue("rhizopus:canvas:framerate", 1), // 120
    .osdColor = sf.getColor("rhizopus:canvas:osdColor"),
    .osdActive = (bool)sf.getValue("rhizopus:canvas:osdActive", false),
    .backgroundColor = sf.getColor("rhizopus:canvas:backgroundColor"),
    .antialiasing = (bool)sf.getValue("rhizopus:canvas:antialiasing", true)
  };
}
