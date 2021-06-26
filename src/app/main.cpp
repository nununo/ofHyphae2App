#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  ofSetupOpenGL(3072, 1920, OF_FULLSCREEN);      // <-------- setup the GL context
  ofRunApp(new ofApp());

  /*
  ofGLWindowSettings settings;
  settings.setGLVersion(3,2);
  settings.setSize(3072, 1920);
    //  settings.windowMode = OF_WINDOW;
  settings.windowMode = OF_FULLSCREEN;
  auto mainWin = ofCreateWindow(settings);      // <-------- setup the GL context
  auto app = make_shared<ofApp>();
  ofRunApp( mainWin, app );
  ofRunMainLoop();
   */
}
