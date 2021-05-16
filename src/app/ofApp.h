#pragma once

#include "ofMain.h"
#include "FieldPainter.h"
#include "Hyphae.h"
#include "Settings.h"
#include "IField.h"
#include "FieldParams.h"

class ofApp : public ofBaseApp{
private:
  shared_ptr<IField> field;
  unique_ptr<Hyphae> hyphae;

  std::shared_ptr<IField> createField(std::shared_ptr<FieldParams> params, const glm::vec2 size);
  std::unique_ptr<Hyphae> createHyphae(std::shared_ptr<HyphaParams> params, std::shared_ptr<IField> field);

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
