#pragma once

#include "ofMain.h"
#include "IFieldPainter.h"
#include "IHyphaePainter.h"
#include "Hyphae.h"
#include "IField.h"
#include "OSD.h"
#include "Params.h"

class ofApp : public ofBaseApp{
private:
  shared_ptr<const Params> params;
  shared_ptr<IField> field;
  unique_ptr<Hyphae> hyphae;
  unique_ptr<IFieldPainter> fieldPainter;
  unique_ptr<IHyphaePainter> hyphaePainter;
  unique_ptr<IHyphaePainter> hyphaePainterBlack;
  unique_ptr<OSD> osd;
  
  unique_ptr<Hyphae> createHyphae(shared_ptr<HyphaParams> params, shared_ptr<IField> field) const;
  unique_ptr<IFieldPainter> createFieldPainter(glm::vec2 size) const;
  unique_ptr<IHyphaePainter> createHyphaePainter(const ofColor color) const;
  unique_ptr<OSD> createOSD(const CanvasSettings& canvasSettings, shared_ptr<HyphaParams> hyphaParams) const;

  void clearScreen();
  glm::vec2 getSize() const;
  void newHyphae();

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
