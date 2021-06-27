//
//  Settings.h
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#ifndef Settings_h
#define Settings_h

#include "HyphaSettings.h"
#include "CanvasSettings.h"
#include "FieldSettings.h"

class Settings {
public:
  const shared_ptr<const HyphaSettings> hypha;
  const shared_ptr<const CanvasSettings> canvas;
  const shared_ptr<const FieldSettings> field;

  Settings(const SettingsFile& sf);
};

#endif /* Settings_h */
