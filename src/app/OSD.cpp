//
//  OSD.cpp
//  hyphaeApp
//
//  Created by Nuno on 23/02/2019.
//

#include "OSD.h"

OSD::OSD(shared_ptr<const CanvasSettings> _canvasSettings)
:canvasSettings(_canvasSettings)
{
  active = canvasSettings->osdActive;
}


void OSD::draw(const HyphaeStats &hyphaeStats, const HyphaParams &hyphaParams, const string fadeStatusString) {
  if (!active) {
    return;
  }
  drawBackground();
  drawInfo(hyphaeStats, hyphaParams, fadeStatusString);
}

void OSD::drawBackground() {
  ofPushStyle();
  ofSetColor(canvasSettings->backgroundColor);
  ofDrawRectangle(0, 0, 400, 320);
  ofPopStyle();
}

void OSD::drawLine(const string text) {
  ofDrawBitmapString(text, 10,distance*(1+currentLine++));
}
 
void OSD::drawInfo(const HyphaeStats& hyphaeStats, const HyphaParams &hyphaParams, const string fadeStatusString) {
  currentLine = 0;

  ofPushStyle();
  ofSetColor(canvasSettings->osdColor);

  drawLine("");

  drawLine("hypha");
  drawLine(" speed: " + ofToString(hyphaParams.speed));
  drawLine(" birth rays: " + ofToString(hyphaParams.birthRays) + " @ " + ofToString(hyphaParams.birthRayDirections));
  drawLine(" max fork angle: " + ofToString(glm::degrees(hyphaParams.maxForkAngle)));
  drawLine(" max bend angle: " + ofToString(glm::degrees(hyphaParams.maxBendAngle)));
  drawLine(" fork distance interval: " + ofToString(hyphaParams.forkDistanceInterval));
  drawLine(" food2energy ratio: " + ofToString(hyphaParams.foodToEnergyRatio));
  drawLine(" energy spent to move: " + ofToString(hyphaParams.energySpentToMove));
  drawLine(" fertilityRatio: " + ofToString(hyphaParams.fertilityRatio));

  drawLine("");

  drawLine("stats");
  drawLine(" framerate: " + ofToString(ofGetFrameRate(),2));
  drawLine(" hyphae lifetime: " + ofToString(hyphaeStats.lifetime ,2));
  drawLine(" alive: " + ofToString(hyphaeStats.alive) + " / " + ofToString(hyphaParams.maxElements) +
   " (+" + ofToString(hyphaeStats.born) + " -" + ofToString(hyphaeStats.died) + ")");
  drawLine(" moved: " + ofToString(hyphaeStats.moved));
  drawLine(" fertility %: " + ofToString(hyphaeStats.fertilityRatio * 100.0f));
  drawLine(" fade status: " + fadeStatusString);

  ofPopStyle();
}
