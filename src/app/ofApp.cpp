#include "ofApp.h"
#include "Params.h"

//--------------------------------------------------------------
void ofApp::setup(){
  settings.reset(new Settings(SettingsFile("settings/settings.xml")));

  field.reset(new Field(settings->field, ofGetWidth(), ofGetHeight()));
  fieldPainter.reset(new FieldPainter(field.get()));

  painter.reset(new Painter(1, ofColor::red));

  Params params(*settings.get());
  HyphaKynetics kynetics(params.hypha, {400, 500}, {1,0});
  hypha.reset(new Hypha(params.hypha, *field.get(), kynetics, 0.5f));

  ofSetFrameRate(settings->canvas.framerate);
  ofSetBackgroundAuto(false);
  ofBackground(ofColor::white);
}

//--------------------------------------------------------------
void ofApp::update(){
  fieldPainter->update();
  hypha->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  if (ofGetFrameNum()<5) {
    fieldPainter->draw();
  }
  painter->clear();
  hypha->paint(painter.get());
  painter->draw();
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
