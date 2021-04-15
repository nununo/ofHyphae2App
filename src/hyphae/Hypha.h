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
#include "HyphaForkEventArgs.h"

class Hypha {
  
private:
  const HyphaParams params;
  const Field field;
  unique_ptr<Painter> painter;
  glm::vec2 pos;
  glm::vec2 dir;
  float energy;

  glm::vec2 nextDirection(const glm::vec2 _dir) const {return glm::rotate(_dir, ofRandom(-params.maxBendAngle, params.maxBendAngle));}
  glm::vec2 nextPosition(const glm::vec2 _pos, glm::vec2 _dir) const {return _pos + _dir;}
  float nextEnergy(float _energy) const {return _energy - params.energySpentToMove;}
  float nextForkAngle(glm::vec2 _dir) const {return glm::angle({1,0}, _dir) + ofRandom(-params.maxForkAngle, params.maxForkAngle);}

  void throwForkEvent();

public:
  Hypha(const HyphaParams params, const Field& _field, const glm::vec2 _pos, const glm::vec2 _dir, const float initialEnergy);
  void update();
  void draw() const {painter->draw();}
  bool isAlive() const {return energy>0;}
  
  ofEvent<HyphaForkEventArgs> forkEvent;
};

#endif /* Hypha_h */
