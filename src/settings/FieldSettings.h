//
//  FieldSettings.h
//  rhizopusApp
//
//  Created by Nuno on 15/04/2021.
//

#ifndef FieldSettings_h
#define FieldSettings_h

#include "ofMain.h"
#include "SettingsFile.h"

class FieldSettings {
public:
  const Range frequency;
  const Range amplification;

  FieldSettings(const SettingsFile& sf);
};

#endif /* FieldSettings_h */
