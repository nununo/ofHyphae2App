//
//  SettingsFactory.h
//  rhizopusApp
//
//  Created by Nuno on 14/04/2021.
//

#ifndef SettingsFactory_h
#define SettingsFactory_h

#include "Settings.h"
#include "SettingsFile.h"

class SettingsFactory {
private:
  CanvasSettings buildCanvasSettings(const SettingsFile& sf);
  HyphaSettings buildHyphaSettings(const SettingsFile& sf);

public:
  Settings* getInstance(const string& xmlFilename);
};
#endif /* SettingsFactory_h */
