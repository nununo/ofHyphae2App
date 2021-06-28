//
//  CanvasSettings.h
//  rhizopusApp
//
//  Created by Nuno on 15/04/2021.
//

#ifndef CanvasSettings_h
#define CanvasSettings_h

#include "ofMain.h"
#include "SettingsFile.h"

struct CanvasSettings {
  const int framerate;
  const bool osdActive;
  const ofColor osdColor;
  const ofColor backgroundColor;
  const bool saveImages;

  CanvasSettings(const SettingsFile& sf);
};

#endif /* CanvasSettings_h */
