#pragma once

#include "ofMain.h"
#include "IFieldPainter.h"
#include "IHyphaePainter.h"
#include "Hyphae.h"
#include "IField.h"
#include "OSD.h"
#include "Params.h"
#include "FadePainter.h"

class ofApp : public ofBaseApp{
private:
  unique_ptr<Settings> settings;
  shared_ptr<Params> params;
  shared_ptr<IField> field;
  unique_ptr<Hyphae> hyphae;
  unique_ptr<IFieldPainter> fieldPainter;
  unique_ptr<IHyphaePainter> hyphaePainter;
  unique_ptr<IHyphaePainter> hyphaePainterField;
  unique_ptr<FadePainter> fadePainter;
  unique_ptr<OSD> osd;
  int dissolve = 0;
  
  unique_ptr<Hyphae> createHyphae(shared_ptr<HyphaParams> params) const;
  unique_ptr<IFieldPainter> createFieldPainter(glm::vec2 size) const;
  unique_ptr<IHyphaePainter> createHyphaePainter(const ofColor color, const glm::vec2 offset, const ofBlendMode blendMode = OF_BLENDMODE_ALPHA) const;
  unique_ptr<OSD> createOSD(const CanvasSettings& canvasSettings) const;
  unique_ptr<FadePainter> createFadePainter(const CanvasSettings& canvasSettings) const;
  shared_ptr<IField> createField(shared_ptr<FieldParams> params, const glm::vec2 size) const;
  shared_ptr<Params> createParams(Settings &settings) const;

  void clearScreen();
  glm::vec2 getSize() const;
  void newHyphae();
  void drawField();
  void fadeOut();

public:
    void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
