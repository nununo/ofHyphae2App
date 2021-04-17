//
//  Hypha.h
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
  HyphaParams params;
  Field field;
  unique_ptr<Painter> painter;
  glm::vec2 pos;
  glm::vec2 dir;
  double energy;

  glm::vec2 nextDirection(const glm::vec2 _dir) const {return glm::rotate(_dir, ofRandom(-params.maxBendAngle, params.maxBendAngle));}
  glm::vec2 nextPosition(const glm::vec2 _pos, glm::vec2 _dir) const {return _pos + _dir;}
  double nextForkAngle(glm::vec2 _dir) const {return glm::angle({1,0}, _dir) + ofRandom(-params.maxForkAngle, params.maxForkAngle);}

  double takeEnergyFromField() {return field.consume(pos, params.foodAmount) * params.foodToEnergyRatio;}
  void updateEnergy() {auto energyFromField = takeEnergyFromField(); energy = energy - params.energySpentToMove + energyFromField;}
  void throwForkEvent();

public:
  Hypha(const HyphaParams& _params, const Field& _field, const glm::vec2 _pos, const glm::vec2 _dir, const double initialEnergy);
  void update();
  void draw() const {painter->draw();}
  bool isAlive() const {return energy>0;}
  
  ofEvent<HyphaForkEventArgs> forkEvent;
};

#endif /* Hypha_h */
