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
  ofBackground(ofColor::white); //(settings.canvas.backgroundColor);

  newHyphae();
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
  params = createParams(*settings);
  field = createField(params->field, canvas->getSize());
  hyphae = createHyphae(params->hypha);
  canvas->reset();
}

unique_ptr<Hyphae> ofApp::createHyphae(shared_ptr<HyphaParams> hyphaParams) const {
  return std::make_unique<Hyphae>(
    hyphaParams,
    make_unique<HyphaCoordinatesRadialGenerator>(glm::radians(80.0f), hyphaParams->birthRayDirections, hyphaParams->birthRays)); // TODO
}

std::shared_ptr<IField> ofApp::createField(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto field = make_shared<WritableField>(size);
  do {
    field->generate(NoiseFieldGenerator(fieldParams));
  } while (!field->hasEnoughFoodAtPosition({0,ofGetScreenHeight()/2})); // TODO
  return field;
}

std::shared_ptr<Params> ofApp::createParams(Settings &settings) const {
  return shared_ptr<Params>(make_shared<Params>(settings));
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
