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

void ofApp::setup(){
  Settings settings(SettingsFile("settings/settings.xml"));
  Params params(settings);

  glm::vec2 size = {ofGetWidth()/2, ofGetHeight()};
  field = createField(params.field, size);

  fieldPainter = std::make_unique<FieldPainter>(field.get());
  painter = std::make_unique<Painter>(settings.hypha.color);

  PerimeterStartPos startPos(field, 10);
  std::unique_ptr<IHyphaCoordinatesGenerator> hyphaCoordinatesGenerator = std::make_unique<HyphaCoordinatesRadialGenerator>(startPos.get(), 10);
  hyphae = std::make_unique<Hyphae>(params.hypha, field, std::move(hyphaCoordinatesGenerator));

  ofSetFrameRate(settings.canvas.framerate);
  ofSetBackgroundAuto(false);
  ofDisableAntiAliasing();
  ofBackground(ofColor::white);
}

void ofApp::update(){
  hyphae->update();
  fieldPainter->update();
}

void ofApp::draw(){
  painter->draw(hyphae->getNewPositions());

  ofPushView();
  ofTranslate(ofGetWidth()/2, 0);
  fieldPainter->draw();
  painter->draw(hyphae->getNewPositions());
  ofPopView();
  
  ofLog() << " total: " << hyphae->count() << " moved: " << hyphae->getNewPositions().size();

  hyphae->clearNewPositions();
}

std::shared_ptr<IField> ofApp::createField(FieldParams params, glm::vec2 size) {
  auto noise = std::make_unique<NoiseFieldGenerator>();
  auto thresholdNoise = std::make_unique<ThresholdFieldGenerator>(std::move(noise), params.zeroThreshold);

  auto lines = std::make_unique<MultiFieldGenerator>(std::make_shared<MaxFunc>());
  for(auto i=0; i<3; i++) {
    lines->add(std::make_unique<LineFieldGenerator>(200/size.x, 1));
  }

  auto interception = std::make_shared<MultiFieldGenerator>(std::make_shared<MinFunc>());
  interception->add(std::move(lines));
  interception->add(std::move(thresholdNoise));

  auto field = std::make_shared<WritableField>(size);
  field->generate(interception);
  return field;
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
