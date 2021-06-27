#include "ofApp.h"
#include "HyphaCoordinatesRadialGenerator.h"
#include "HyphaePainter.h"
#include "FieldPainter.h"
#include "NoiseFieldGenerator.h"
#include "WritableField.h"

void ofApp::setup(){
  settings = std::make_unique<Settings>(SettingsFile("settings/settings.xml"));
  params = createParams(*settings);

  fieldPainter = createFieldPainter(getSize());
  osd = createOSD(settings->canvas);
  hyphaePainter = createHyphaePainter(params->hypha->color, OF_BLENDMODE_SUBTRACT);
  hyphaePainterField = createHyphaePainter(ofColor::red);

  ofSetFrameRate(settings->canvas.framerate);
  ofSetBackgroundAuto(false);
  ofDisableAntiAliasing();
  ofBackground(ofColor::white); //(settings.canvas.backgroundColor);

  newHyphae();
}

void ofApp::update(){
  hyphae->update(*field.get());
  if (!hyphae->isAlive()) {
    if (++dissolve % 600 == 0) {
      newHyphae();
    } else if (dissolve > 200){
      fadeOut();
    }
  }
}

void ofApp::draw() {
  hyphaePainter->draw(hyphae->getNewPositions());
  osd->draw(hyphae->getStats(), *params->hypha);

}

void ofApp::newHyphae() {
  params = createParams(*settings);
  field = createField(params->field, getSize());
  hyphae = createHyphae(params->hypha);
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
  hyphaePainterField->draw(hyphae->getNewPositions());
  ofPopView();
}

glm::vec2 ofApp::getSize() const {
  return {ofGetWidth(), ofGetHeight()};
}

unique_ptr<Hyphae> ofApp::createHyphae(shared_ptr<HyphaParams> hyphaParams) const {
  return std::make_unique<Hyphae>(
    hyphaParams,
    make_unique<HyphaCoordinatesRadialGenerator>(hyphaParams->birthAreaRadius, 1, hyphaParams->birthRayDirections, hyphaParams->birthRays));
}

std::shared_ptr<IField> ofApp::createField(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto field = make_shared<WritableField>(size);
  field->generate(NoiseFieldGenerator(fieldParams));
  return field;
}

std::shared_ptr<Params> ofApp::createParams(Settings &settings) const {
  return shared_ptr<Params>(make_shared<Params>(settings));
}

unique_ptr<IFieldPainter> ofApp::createFieldPainter(const glm::vec2 size) const {
  return unique_ptr<IFieldPainter>(make_unique<FieldPainter>(size));
}

unique_ptr<IHyphaePainter> ofApp::createHyphaePainter(const ofColor color, const ofBlendMode blendMode) const {
  return unique_ptr<IHyphaePainter>(make_unique<HyphaePainter>(color, blendMode));
}

unique_ptr<OSD> ofApp::createOSD(const CanvasSettings &canvasSettings) const {
  return unique_ptr<OSD>(make_unique<OSD>(canvasSettings));
}

void ofApp::fadeOut() {
  ofPushStyle();
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofSetColor(ofColor(ofColor::white,1));
  ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
  ofPopStyle();
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
