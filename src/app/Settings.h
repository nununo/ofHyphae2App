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
  double speed;
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
  HyphaSettings hyphaSettings() {return _hyphaSettings;}
  CanvasSettings canvasSettings() {return _canvasSettings;}
};
#endif /* Settings_h */
