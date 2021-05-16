#include "ofApp.h"
#include "Params.h"
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

void ofApp::setup(){
  Settings settings(SettingsFile("settings/settings.xml"));
  auto params = std::make_shared<Params>(settings);

  glm::vec2 size = {ofGetWidth()/2, ofGetHeight()};

  field = createField(params->field, size);
  fieldPainter = createFieldPainter(size);
  hyphae = createHyphae(params->hypha, field);

  ofSetFrameRate(settings.canvas.framerate);
  ofSetBackgroundAuto(false);
  ofDisableAntiAliasing();
  ofBackground(ofColor::white);
}

void ofApp::update(){
  hyphae->update(*field.get());
}

void ofApp::draw(){
  hyphae->draw();

  ofPushView();
  ofTranslate(ofGetWidth()/2, 0);
  fieldPainter->draw(*field.get());
  ofPopView();
  
  ofLog() << " total: " << hyphae->count();
}

std::shared_ptr<IField> ofApp::createField(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto noise = std::make_unique<NoiseFieldGenerator>();
  auto thresholdNoise = std::make_unique<ThresholdFieldGenerator>(std::move(noise), fieldParams->zeroThreshold);

  auto lines = std::make_unique<MultiFieldGenerator>(std::make_shared<MaxFunc>());
  for(auto i=0; i<5; i++) {
    lines->add(std::make_unique<LineFieldGenerator>(100/size.x, 1));
  }

  auto interception = std::make_shared<MultiFieldGenerator>(std::make_shared<MinFunc>());
  interception->add(std::move(lines));
  interception->add(std::move(thresholdNoise));

  auto field = std::make_shared<WritableField>(size);
  field->generate(interception);
  return field;
}

unique_ptr<Hyphae> ofApp::createHyphae(std::shared_ptr<HyphaParams> hyphaParams, std::shared_ptr<IField> field) const {
  PerimeterStartPos startPos(field, 50);
  return std::make_unique<Hyphae>(
    hyphaParams,
    std::make_unique<HyphaCoordinatesRadialGenerator>(startPos.get(), 10),
    std::make_unique<HyphaePainter>(hyphaParams->color));
}

unique_ptr<IFieldPainter> ofApp::createFieldPainter(const glm::vec2 size) const {
  return unique_ptr<IFieldPainter>(make_unique<FieldPainter>(size));
}

void ofApp::keyPressed(int key){}
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
