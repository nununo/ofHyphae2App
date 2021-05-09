#include "ofApp.h"
#include "Params.h"
#include "NoiseFieldGenerator.h"
#include "MultiFieldGenerator.h"
#include "MaxFunc.h"
#include "ThresholdFieldGenerator.h"
#include "LineFieldGenerator.h"
#include "WritableField.h"

void ofApp::setup(){
  settings.reset(new Settings(SettingsFile("settings/settings.xml")));
  Params params(*settings.get());

  glm::vec2 size = {ofGetWidth()/2, ofGetHeight()};
  field = createField(params.field, size);

  fieldPainter.reset(new FieldPainter(field.get()));
  painter.reset(new Painter(settings->hypha.color));

  HyphaCoordinates hyphaCoordinates = {{100, 100}, {1,0}};
  hyphae.reset(new Hyphae(params.hypha, field.get(), hyphaCoordinates));

  ofSetFrameRate(settings->canvas.framerate);
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


void ofApp::keyPressed(int key){
}

std::unique_ptr<IField> ofApp::createField(FieldParams params, glm::vec2 size) {
  //auto noiseFieldGenerator = NoiseFieldGenerator();
  //const auto thresholdFieldGenerator = ThresholdFieldGenerator(&noiseFieldGenerator,params.zeroThreshold);

  MultiFieldGenerator multiFieldGenerator(std::make_shared<MaxFunc>());
  multiFieldGenerator.add(std::make_unique<LineFieldGenerator>(200/size.x, 1));
  multiFieldGenerator.add(std::make_unique<LineFieldGenerator>(200/size.x, 1));
  multiFieldGenerator.add(std::make_unique<LineFieldGenerator>(200/size.x, 1));

  auto field = std::make_unique<WritableField>(size);
  field->write(&multiFieldGenerator);
  return field;
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
