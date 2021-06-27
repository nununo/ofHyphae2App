#pragma once

#include "ofMain.h"
#include "Hyphae.h"
#include "IField.h"
#include "Params.h"
#include "Canvas.h"

class ofApp : public ofBaseApp{
private:
  shared_ptr<Settings> settings;
  shared_ptr<Params> params;
  shared_ptr<IField> field;
  unique_ptr<Hyphae> hyphae;
  unique_ptr<Canvas> canvas;
  int dissolve = 0;
  
  unique_ptr<Hyphae> createHyphae(shared_ptr<HyphaParams> params) const;
  shared_ptr<IField> createField(shared_ptr<FieldParams> params, const glm::vec2 size) const;
  shared_ptr<Params> createParams(Settings &settings) const;

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
