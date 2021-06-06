//
//  HyphaSettings.h
//  rhizopusApp
//
//  Created by Nuno on 15/04/2021.
//

#ifndef HyphaSettings_h
#define HyphaSettings_h

#include "SettingsFile.h"
#include "MinMaxVec2.h"

class HyphaSettings {
public:
  const ofColor color;
  const glm::vec2 speed;
  const MinMaxVec2 energySpentToMove;
  const glm::vec2 maxBendAngle;
  const glm::vec2 maxForkAngle;
  const glm::vec2 foodToEnergyRatio;
  const MinMaxVec2 forkDistance;
  const glm::vec2 birthAreaRadius;
  const glm::vec2 maxGrowthPercentage;
  const double pixelOverlap;

  HyphaSettings(const SettingsFile& sf);
};

#endif /* HyphaSettings_h */
