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
  const glm::vec2 size;

  unique_ptr<OSD> osd;
  unique_ptr<IFieldPainter> fieldPainter;
  unique_ptr<IHyphaePainter> hyphaePainter;
  unique_ptr<IHyphaePainter> hyphaePainterField;
  unique_ptr<FadePainter> fadePainter;
  
  bool savedToFile;
  int savedFileCounter = 1;
  bool horizontalFlip;

  unique_ptr<IHyphaePainter> createHyphaePainter(const ofColor color, const glm::vec2 offset, const ofBlendMode blendMode = OF_BLENDMODE_ALPHA) const;
  void drawHyphae(const vector<glm::vec3> hyphaPositions);
  bool calcHorizontalFlip();

public:
  Canvas(shared_ptr<const CanvasSettings> settings, ofColor hyphaColor);
  void saveToFile();
  void draw(
            const HyphaeStats &hyphaeStats,
            const HyphaParams &hyphaParams,
            const vector<glm::vec3> hyphaPositions);
  void toggleOSDActive();
  void drawField(const IField &field);
  void clear();
  bool getFadeEnded() const;
  void reset();
  glm::vec2 getSize() const;
};

#endif /* Canvas_h */
