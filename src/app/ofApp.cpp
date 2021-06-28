#include "ofApp.h"
#include "HyphaCoordinatesRadialGenerator.h"
#include "NoiseFieldGenerator.h"
#include "WritableField.h"

void ofApp::setup(){
  settings = make_shared<Settings>(SettingsFile("settings/settings.xml"));
  canvas = make_unique<Canvas>(settings->canvas, settings->hypha->color);

  ofSetFrameRate(settings->canvas->framerate);
  ofSetBackgroundAuto(false);
  ofDisableAntiAliasing();
  ofBackground(settings->canvas->backgroundColor);

  newHyphae();
  ofHideCursor();
}

void ofApp::update(){
  hyphae->update(*field.get());
  if (canvas->getFadeEnded()) {
    newHyphae();
  }
}

void ofApp::draw() {
  canvas->draw(hyphae->getStats(), *params->hypha, hyphae->getNewPositions());
}

void ofApp::newHyphae() {
  params = make_shared<Params>(*settings);
  field = createField();
  hyphae = createHyphae(params->hypha);
  canvas->reset();
}

unique_ptr<Hyphae> ofApp::createHyphae(shared_ptr<HyphaParams> hyphaParams) const {
  return make_unique<Hyphae>(
    hyphaParams,
    make_unique<HyphaCoordinatesRadialGenerator>(
      glm::radians(80.0f),                         // TODO
      hyphaParams->birthRayDirections,
      hyphaParams->birthRays));
}

unique_ptr<IField> ofApp::createField() const {
  auto writableField = make_unique<WritableField>(canvas->getSize());
  do {
    writableField->generate(NoiseFieldGenerator(params->field));
  } while (!writableField->hasEnoughFoodAtPosition({0,ofGetScreenHeight()/2})); // TODO
  return writableField;
}

void ofApp::keyPressed(int key) {
  switch (key) {
  case 'n':
    newHyphae();
    break;
  case 'f':
    canvas->drawField(*field);
    break;
  case 'o':
    canvas->toggleOSDActive();
    break;
  case 'c':
    canvas->clear();
    break;
  case 's':
    canvas->saveToFile();
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
