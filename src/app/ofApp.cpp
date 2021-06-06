#include "ofApp.h"
#include "NoiseFieldGenerator.h"
#include "MultiFieldGenerator.h"
#include "MaxFunc.h"
#include "MinFunc.h"
#include "ThresholdFieldGenerator.h"
#include "LineFieldGenerator.h"
#include "WritableField.h"
#include "PerimeterStartPos.h"
#include "HyphaCoordinatesRadialGenerator.h"
#include "HyphaePainter.h"
#include "FieldPainter.h"

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
  auto density = hyphae->getDensity();
  auto center = hyphae->getCenterOfMass();
  ofDrawEllipse(center, density, density);
  ofPopStyle();
  
  osd->draw(hyphae->getStats());
  ofPopView();
}

void ofApp::newHyphae() {
  field = createField(params->field, getSize());
  hyphae = createHyphae(params->hypha, field);
}

glm::vec2 ofApp::getSize() const {
  return {ofGetWidth()/2, ofGetHeight()};
}

std::shared_ptr<IField> ofApp::createField(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto noise = std::make_unique<NoiseFieldGenerator>();
  auto thresholdNoise = std::make_unique<ThresholdFieldGenerator>(std::move(noise), fieldParams->zeroThreshold);

  auto lines = std::make_unique<MultiFieldGenerator>(std::make_shared<MaxFunc>());
  for(auto i=0; i<3; i++) { // TODO
    lines->add(std::make_unique<LineFieldGenerator>(200/size.x, 1)); // TODO
  }

  auto interception = make_shared<MultiFieldGenerator>(make_shared<MinFunc>());
  interception->add(move(lines));
  interception->add(move(thresholdNoise));

  auto field = make_shared<WritableField>(size);
  field->generate(interception);
  return field;
}

unique_ptr<Hyphae> ofApp::createHyphae(shared_ptr<HyphaParams> hyphaParams, shared_ptr<IField> field) const {
  PerimeterStartPos startPos(field, 50); // TODO
  return std::make_unique<Hyphae>(
    hyphaParams,
    make_unique<HyphaCoordinatesRadialGenerator>(field, startPos.get(), hyphaParams->birthAreaRadius, 1, 10)); // TODO
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

void ofApp::keyPressed(int key) {
  switch (key) {
  case ' ':
    newHyphae();
    break;
  case 'f':
    ofToggleFullscreen();
    break;
  case 'o':
    osd->toggleActive();
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
