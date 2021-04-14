//
//  Painter.h
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

#ifndef Painter_h
#define Painter_h

#include "ofMain.h"

class Painter {
private:
  ofVboMesh mesh;
  ofColor color;
  
public:
  Painter(int maxSize, const ofColor color);
  void clear() {mesh.clear();}
  void add(glm::vec2 pos);
  void draw();
};

#endif /* Painter_h */
