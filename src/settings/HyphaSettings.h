//
//  HyphaSettings.h
//  rhizopusApp
//
//  Created by Nuno on 15/04/2021.
//

#ifndef HyphaSettings_h
#define HyphaSettings_h

#include "ofMain.h"
#include "SettingsFile.h"

class HyphaSettings {
public:
  const ofColor color;
  const glm::vec2 speed;
  const glm::vec2 energySpentToMove;
  const glm::vec2 maxBendAngle;
  const glm::vec2 maxForkAngle;
  const glm::vec2 foodAmount;
  const glm::vec2 foodToEnergyRatio;

  HyphaSettings(const SettingsFile& sf);
};

#endif /* HyphaSettings_h */
