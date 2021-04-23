#pragma once

#include "ofMain.h"
#include "FieldPainter.h"
#include "Hyphae.h"
#include "Settings.h"
#include "Painter.h"

class ofApp : public ofBaseApp{
private:
  unique_ptr<Settings> settings;
  unique_ptr<IField> field;
  unique_ptr<FieldPainter> fieldPainter;
  unique_ptr<Hyphae> hyphae;
  unique_ptr<Painter> painter;

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
