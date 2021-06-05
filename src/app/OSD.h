//
//  OSD.h
//  rhizopusApp
//
//  Created by Nuno on 23/02/2019.
//

#ifndef OSD_h
#define OSD_h

#include "CanvasSettings.h"
#include "HyphaeStats.h"
#include "HyphaParams.h"

class OSD {
private:
  const int distance = 15;
  const CanvasSettings canvasSettings;
  shared_ptr<HyphaParams> hyphaParams;

  bool active;
  int currentLine = 0;

  void drawBackground();
  void drawInfo(const HyphaeStats& hyphaeStats);
  void drawLine(const string text);

public:
  OSD(const CanvasSettings& canvasSettings, shared_ptr<HyphaParams> hyphaParams);
  void draw(const HyphaeStats& hyphaeStats);
  void toggleActive() {active=!active;}
};

#endif /* OSD_h */
