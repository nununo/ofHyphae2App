//
//  Hypha.hpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#ifndef Hypha_h
#define Hypha_h

#include "ofMain.h"
#include "Field.h"
#include "Painter.h"

class Hypha {
  
private:
  glm::vec2 pos;
  glm::vec2 dir;
  float energy;
  const Field *field;
  unique_ptr<Painter> painter;

public:
  Hypha(const Field *field, const glm::vec2 _pos, const glm::vec2 _dir, const float energy);
  void update();
  void draw();
};

#endif /* Hypha_h */
