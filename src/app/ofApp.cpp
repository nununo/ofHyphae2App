#include "ofApp.h"
#include "LeftRightStartPos.h"
#include "HyphaCoordinatesLeftRightGenerator.h"
#include "HyphaePainter.h"
#include "FieldPainter.h"
#include "NoiseFieldGenerator.h"
#include "WritableField.h"
#include "ScreenOccupancy.h"

void ofApp::setup() {
  Settings settings(SettingsFile("settings/settings.xml"));
  params = std::make_shared<Params>(settings);

  fieldPainter = createFieldPainter(getSize());
  osd = createOSD(settings.canvas, params->hypha);
  occupancy = createOccupancy(getSize());
  hyphaePainter = createHyphaePainter(params->hypha->color);
  hyphaePainterBlack = createHyphaePainter(ofColor::red);

  ofSetFrameRate(settings.canvas.framerate);
  ofSetBackgroundAuto(false);
  ofDisableAntiAliasing();
  ofBackground(ofColor::white); //(settings.canvas.backgroundColor);

  newHyphae();
}

void ofApp::update(){
  occupancy->update();
  hyphae->update(*field.get());
  if (!hyphae->isAlive()) {
    newHyphae();
  }
}

void ofApp::draw() {
  hyphaePainter->draw(hyphae->getNewPositions());
  osd->draw(hyphae->getStats());
}

void ofApp::newHyphae() {
  field = createField(params->field, getSize());
  hyphae = createHyphae(params->hypha, field, occupancy);
  clearScreen();
}

/**
 Draw scaled field and moving particles on top right corner
 */
void ofApp::drawField() {
  ofPushView();
  ofTranslate(field->getSize().x-field->getSize().x/5, 0);
  ofScale(0.20f);
  fieldPainter->draw(*field.get());
  hyphaePainterBlack->draw(hyphae->getNewPositions());
  ofPopView();
}

glm::vec2 ofApp::getSize() const {
  return {ofGetWidth(), ofGetHeight()};
}

unique_ptr<Hyphae> ofApp::createHyphae(shared_ptr<HyphaParams> hyphaParams, shared_ptr<IField> field, shared_ptr<IOccupancy> occupancy) const {
  LeftRightStartPos startPos(field, 50); // TODO
  return std::make_unique<Hyphae>(
    hyphaParams,
    make_unique<HyphaCoordinatesLeftRightGenerator>(startPos.get(), hyphaParams->birthRays),
    occupancy);
}

std::shared_ptr<IField> ofApp::createField(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto field = make_shared<WritableField>(size);
  field->generate(NoiseFieldGenerator());
  return field;
}

unique_ptr<IFieldPainter> ofApp::createFieldPainter(const glm::vec2 size) const {
  return unique_ptr<IFieldPainter>(make_unique<FieldPainter>(size));
}

unique_ptr<IHyphaePainter> ofApp::createHyphaePainter(const ofColor color) const {
  return unique_ptr<IHyphaePainter>(make_unique<HyphaePainter>(color));
}

unique_ptr<OSD> ofApp::createOSD(const CanvasSettings &canvasSettings, shared_ptr<HyphaParams> hyphaParams) const {
  return unique_ptr<OSD>(make_unique<OSD>(canvasSettings, hyphaParams));
}

shared_ptr<IOccupancy> ofApp::createOccupancy(const glm::vec2 size) const {
  return shared_ptr<IOccupancy>(make_shared<ScreenOccupancy>(size, 20));
}

void ofApp::clearScreen() {
  ofClear(ofColor::white);
}

void ofApp::keyPressed(int key) {
  switch (key) {
  case 'n':
    newHyphae();
    break;
  case 'f':
    drawField();
    break;
  case 'o':
    osd->toggleActive();
    break;
  case 'y':
    occupancy->draw({500,0}, {640,400});
    break;
  case 'c':
    clearScreen();
    break;
  default:
    break;
  }
}

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
