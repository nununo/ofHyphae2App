//
//  Canvas.h
//  rhizopusApp
//
//  Created by Nuno on 27/06/2021.
//

#ifndef Canvas_h
#define Canvas_h

#include "CanvasSettings.h"
#include "OSD.h"
#include "HyphaeStats.h"
#include "HyphaParams.h"
#include "IFieldPainter.h"
#include "IHyphaePainter.h"
#include "FadePainter.h"

class Canvas {
  shared_ptr<const CanvasSettings> settings;
  const string filenamePrefix;
  unique_ptr<OSD> osd;
  unique_ptr<IFieldPainter> fieldPainter;
  unique_ptr<IHyphaePainter> hyphaePainter;
  unique_ptr<IHyphaePainter> hyphaePainterField;
  unique_ptr<FadePainter> fadePainter;

  int savedFileCounter = 0;

  unique_ptr<IHyphaePainter> createHyphaePainter(const ofColor color, const glm::vec2 offset, const ofBlendMode blendMode = OF_BLENDMODE_ALPHA) const;

public:
  Canvas(shared_ptr<const CanvasSettings> settings, ofColor hyphaColor);
  void saveScreen();
  void draw(
            const HyphaeStats &hyphaeStats,
            const HyphaParams &hyphaParams,
            const vector<glm::vec3> hyphaPositions);
  void toggleOSDActive();
  glm::vec2 getSize() const;
  void drawField(const IField &field);
  void clear();
  bool getFadeEnded() const;
  void reset();
};

#endif /* Canvas_h */
