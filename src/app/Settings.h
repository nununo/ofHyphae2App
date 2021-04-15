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
  glm::vec2 maxBendAngleDeg;
};

struct CanvasSettings {
  int framerate;
  bool osdActive;
  ofColor osdColor;
  ofColor backgroundColor;
  bool antialiasing;
};

class Settings {
private:
  HyphaSettings _hyphaSettings;
  CanvasSettings _canvasSettings;

public:
  Settings(HyphaSettings _hyphaSettings, CanvasSettings _canvasSettings);
  HyphaSettings hypha() const {return _hyphaSettings;}
  CanvasSettings canvas() const {return _canvasSettings;}
};
#endif /* Settings_h */
