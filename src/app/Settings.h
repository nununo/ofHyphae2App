//
//  Settings.h
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#ifndef Settings_h
#define Settings_h

#include "ofMain.h"

struct HyphaSettings {
  ofColor color;
  glm::vec2 speed;
  glm::vec2 energySpentToMove;
  glm::vec2 maxBendAngle;
  glm::vec2 maxForkAngle;
  glm::vec2 foodAmount;
  glm::vec2 foodToEnergyRatio;
};

struct CanvasSettings {
  int framerate;
  bool osdActive;
  ofColor osdColor;
  ofColor backgroundColor;
  bool antialiasing;
};

class Settings {
public:
  const HyphaSettings hypha;
  const CanvasSettings canvas;

  Settings(HyphaSettings _hyphaSettings, CanvasSettings _canvasSettings)
  : hypha(_hyphaSettings)
  , canvas(_canvasSettings)
  {}
};
#endif /* Settings_h */
