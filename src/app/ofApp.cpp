#include "ofApp.h"
#include "SettingsFactory.h"

//--------------------------------------------------------------
void ofApp::setup(){
  settings.reset(SettingsFactory().getInstance("settings/settings.xml"));

  field.reset(new Field(ofGetWidth(), ofGetHeight()));
  fieldPainter.reset(new FieldPainter(field.get()));

  HyphaParams hyphaParams(settings.get()->hypha);
  hypha.reset(new Hypha(hyphaParams, *field.get(), {300, 300}, {1,0}, 0.5f));

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
  //fieldPainter->draw();
  hypha->draw();
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
