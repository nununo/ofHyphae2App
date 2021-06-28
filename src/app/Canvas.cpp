//
//  Canvas.cpp
//  rhizopusApp
//
//  Created by Nuno on 27/06/2021.
//

#include "Canvas.h"
#include "FieldPainter.h"
#include "HyphaePainter.h"

Canvas::Canvas(shared_ptr<const CanvasSettings> _settings, ofColor hyphaColor)
: settings{_settings}
, filenamePrefix{"images/hyphae2_" + ofGetTimestampString() + "_"}
, osd{make_unique<OSD>(_settings)}
, fieldPainter{(unique_ptr<IFieldPainter>)make_unique<FieldPainter>(glm::vec2(ofGetWidth(), ofGetHeight()))}
, hyphaePainter{createHyphaePainter(hyphaColor, {_settings->horizontalOffset, 0}, OF_BLENDMODE_SUBTRACT)}
, hyphaePainterField{createHyphaePainter(ofColor::red, {0,0})}
, fadePainter{make_unique<FadePainter>(3*_settings->framerate, 3*_settings->framerate)}
, size{ofGetWidth(), ofGetHeight()}
, savedToFile{!_settings->saveImages}
{}


void Canvas::draw(
  const HyphaeStats &hyphaeStats,
  const HyphaParams &hyphaParams,
  const vector<glm::vec3> hyphaPositions) {
  if (hyphaeStats.isAlive) {
    drawHyphae(hyphaPositions);
    osd->draw(hyphaeStats, hyphaParams, fadePainter->getStatusString());
  } else {
    if (!savedToFile) {
      // Save final canvas to file
      saveToFile();
      savedToFile = true;
    }
    fadePainter->draw();
  }
}

void Canvas::saveToFile() {
  ofSaveScreen(filenamePrefix + ofToString(++savedFileCounter, 5, '0')+".png");
}

void Canvas::reset() {
  horizontalFlip = calcHorizontalFlip();
  fadePainter->reset();
  clear();
  savedToFile = !settings->saveImages;
}

bool Canvas::calcHorizontalFlip() {
  return glm::floor(ofRandom(2.0f)) == 1;
}

void Canvas::toggleOSDActive() {
  osd->toggleActive();
}

glm::vec2 Canvas::getSize() const {
  return size;
}

/**
 Draw scaled field and moving particles on top right corner
 */
void Canvas::drawField(const IField &field) {
  ofPushView();
  ofTranslate(size.x - size.x/5, 0);
  ofScale(0.20f);
  fieldPainter->draw(field);
  //hyphaePainterField->draw(hyphae->getNewPositions());
  ofPopView();
}

void Canvas::drawHyphae(const vector<glm::vec3> hyphaPositions) {
  ofPushView();
  if (horizontalFlip) {
    ofRotateYDeg(180);
    ofTranslate(-size.x, 0);
  }
  hyphaePainter->draw(hyphaPositions);
  ofPopView();
}

unique_ptr<IHyphaePainter> Canvas::createHyphaePainter(const ofColor color, const glm::vec2 offset, const ofBlendMode blendMode) const {
  return unique_ptr<IHyphaePainter>(make_unique<HyphaePainter>(color, offset, blendMode));
}

void Canvas::clear() {
  ofClear(ofColor::white);
}

bool Canvas::getFadeEnded() const {
  return fadePainter->getStatus() == FadeStatus::Ended;
}
