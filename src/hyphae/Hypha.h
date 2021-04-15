//
//  Hypha.hpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#ifndef Hypha_h
#define Hypha_h

#include "Field.h"
#include "Painter.h"
#include "HyphaParams.h"

class Hypha {
  
private:
  const HyphaParams params;
  glm::vec2 pos;
  glm::vec2 dir;
  float energy;
  const Field *field;
  unique_ptr<Painter> painter;

  glm::vec2 nextDirection(const glm::vec2 dir) const;
  glm::vec2 nextPosition(const glm::vec2 pos, glm::vec2 dir) const {return pos + dir;}
public:
  Hypha(const HyphaParams params, const Field *_field, const glm::vec2 _pos, const glm::vec2 _dir, const float initialEnergy);
  void update();
  void draw() const {painter->draw();}
};

#endif /* Hypha_h */
