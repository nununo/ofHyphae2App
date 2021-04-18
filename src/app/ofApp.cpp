#include "ofApp.h"
#include "Params.h"

//--------------------------------------------------------------
void ofApp::setup(){
  settings.reset(new Settings(SettingsFile("settings/settings.xml")));

  field.reset(new Field(settings->field, ofGetWidth(), ofGetHeight()));
  fieldPainter.reset(new FieldPainter(field.get()));

  painter.reset(new Painter(ofColor::red));

  Params params(*settings.get());
  HyphaKynetics kynetics(params.hypha, {400, 500}, {1,0});
  hyphae.reset(new Hyphae(params.hypha, *field.get(), kynetics));

  ofSetFrameRate(settings->canvas.framerate);
  ofSetBackgroundAuto(false);
  ofBackground(ofColor::white);
  ofDisableAntiAliasing();
}

//--------------------------------------------------------------
void ofApp::update(){
  fieldPainter->update();
  if (ofGetFrameNum()>=4) {
    hyphae->update();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  if (ofGetFrameNum()<4) {
    fieldPainter->draw();
  } else {
    painter->draw(hyphae->getNewPositions());
    hyphae->clearNewPositions();
  }
  ofLog() << ofGetFrameNum();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}



//--------------------------------------------------------------
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
