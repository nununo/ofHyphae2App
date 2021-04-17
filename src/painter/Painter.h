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
  ofColor color;
  
public:
  Painter(const ofColor color);
  void draw(std::vector<glm::vec2>);
};

#endif /* Painter_h */
