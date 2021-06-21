#include "ofApp.h"
#include "LeftRightStartPos.h"
#include "HyphaCoordinatesLeftRightGenerator.h"
#include "HyphaePainter.h"
#include "FieldPainter.h"
#include "FieldBuilderNoise.h"

void ofApp::setup(){
  Settings settings(SettingsFile("settings/settings.xml"));
  params = std::make_shared<Params>(settings);

  fieldPainter = createFieldPainter(getSize());
  osd = createOSD(settings.canvas, params->hypha);
  hyphaePainter = createHyphaePainter(params->hypha->color);
  hyphaePainterBlack = createHyphaePainter(ofColor::red);

  ofSetFrameRate(settings.canvas.framerate);
  ofSetBackgroundAuto(false);
  ofDisableAntiAliasing();
  ofBackground(ofColor::white);

  newHyphae();
}

void ofApp::update(){
  hyphae->update(*field.get());
  if (!hyphae->isAlive()) {
    newHyphae();
  }
}

void ofApp::draw(){
  hyphaePainter->draw(hyphae->getNewPositions());

  ofPushView();

  ofTranslate(ofGetWidth()/2, 0);

  fieldPainter->draw(*field.get());
  hyphaePainterBlack->draw(hyphae->getNewPositions());
  
  ofPushStyle();
  ofSetColor(ofColor::green);
  ofNoFill();
  auto hyphaeStats = hyphae->getStats();
  ofDrawEllipse(hyphaeStats.centerOfMass, hyphaeStats.density, hyphaeStats.density);
  ofPopStyle();
  
  osd->draw(hyphaeStats);
  ofPopView();
}

void ofApp::newHyphae() {
  field = FieldBuilderNoise().create(params->field, getSize());
  hyphae = createHyphae(params->hypha, field);
  clearScreen();
}

glm::vec2 ofApp::getSize() const {
  return {ofGetWidth()/2, ofGetHeight()};
}

unique_ptr<Hyphae> ofApp::createHyphae(shared_ptr<HyphaParams> hyphaParams, shared_ptr<IField> field) const {
  LeftRightStartPos startPos(field, 50); // TODO
  return std::make_unique<Hyphae>(
    hyphaParams,
    make_unique<HyphaCoordinatesLeftRightGenerator>(startPos.get(), hyphaParams->birthRays));
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

void ofApp::clearScreen() {
  ofClear(ofColor::white);
}

void ofApp::keyPressed(int key) {
  switch (key) {
  case 'n':
    newHyphae();
    break;
  case 'f':
    ofToggleFullscreen();
    break;
  case 'o':
    osd->toggleActive();
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
