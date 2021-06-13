//
//  OSD.cpp
//  hyphaeApp
//
//  Created by Nuno on 23/02/2019.
//

#include "OSD.h"

OSD::OSD(const CanvasSettings& _canvasSettings, shared_ptr<HyphaParams> _hyphaParams)
:canvasSettings(_canvasSettings)
,hyphaParams(_hyphaParams)
{
  active = canvasSettings.osdActive;
}


void OSD::draw(const HyphaeStats& hyphaeStats) {
  if (!active) {
    return;
  }
  drawBackground();
  drawInfo(hyphaeStats);
}

void OSD::drawBackground() {
  ofPushStyle();
  ofSetColor(canvasSettings.backgroundColor);
  ofDrawRectangle(0, 0, 400, 320);
  ofPopStyle();
}

void OSD::drawLine(const string text) {
  ofDrawBitmapString(text, 10,distance*(1+currentLine++));
}
 
void OSD::drawInfo(const HyphaeStats& hyphaeStats) {
  currentLine = 0;

  ofPushStyle();
  ofSetColor(canvasSettings.osdColor);

  drawLine("");

  drawLine("hypha");
  drawLine(" speed: " + ofToString(hyphaParams->speed));
  drawLine(" max fork angle: " + ofToString(hyphaParams->maxForkAngle));
  drawLine(" max bend angle: " + ofToString(hyphaParams->maxBendAngle));
  drawLine(" fork distance interval: " + ofToString(hyphaParams->forkDistanceInterval));
  drawLine(" food2energy ratio: " + ofToString(hyphaParams->foodToEnergyRatio));
  drawLine(" energy spent to move: " + ofToString(hyphaParams->energySpentToMove));
  drawLine(" birth area radius: " + ofToString(hyphaParams->birthAreaRadius));

  drawLine("");

  drawLine("stats");
  drawLine(" framerate: " + ofToString(ofGetFrameRate(),2));
  drawLine(" hyphae lifetime: " + ofToString(ofGetFrameNum() / canvasSettings.framerate ,2));
  drawLine(" alive: " + ofToString(hyphaeStats.alive));
  drawLine(" moved: " + ofToString(hyphaeStats.moved));
  drawLine(" born: " + ofToString(hyphaeStats.born));
  drawLine(" dead: " + ofToString(hyphaeStats.died));
  drawLine(" fertility %: " + ofToString(hyphaeStats.fertilityRatio * 100.0f));
  drawLine(" density: " + ofToString(hyphaeStats.density));

  drawLine("");
  
  drawLine("antialiasing: " + ofToString(canvasSettings.antialiasing));

  ofPopStyle();
}
