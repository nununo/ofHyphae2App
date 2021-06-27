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
, fieldPainter{(unique_ptr<IFieldPainter>)make_unique<FieldPainter>(getSize())}
, hyphaePainter{createHyphaePainter(hyphaColor, {-70, 0}, OF_BLENDMODE_SUBTRACT)} // TODO
, hyphaePainterField{createHyphaePainter(ofColor::red, {0,0})}
, fadePainter{make_unique<FadePainter>(3*_settings->framerate, 3*_settings->framerate)}
{}

void Canvas::saveScreen() {
  ofSaveScreen(filenamePrefix + ofToString(savedFileCounter++, 5, '0')+".png");
}

void Canvas::reset() {
  fadePainter->reset();
}

void Canvas::draw(
  const HyphaeStats &hyphaeStats,
  const HyphaParams &hyphaParams,
  const vector<glm::vec3> hyphaPositions) {
  if (hyphaeStats.isAlive) {
    hyphaePainter->draw(hyphaPositions);
  } else {
    fadePainter->draw();
  }
  osd->draw(hyphaeStats, hyphaParams, fadePainter->getStatusString());
}

void Canvas::toggleOSDActive() {
  osd->toggleActive();
}

glm::vec2 Canvas::getSize() const {
  return {ofGetWidth(), ofGetHeight()};
}

/**
 Draw scaled field and moving particles on top right corner
 */
void Canvas::drawField(const IField &field) {
  ofPushView();
  ofTranslate(getSize().x - getSize().x/5, 0);
  ofScale(0.20f);
  fieldPainter->draw(field);
  //hyphaePainterField->draw(hyphae->getNewPositions());
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
