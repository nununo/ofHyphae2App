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
#include "HyphaKynetics.h"

class Hypha {
  
private:
  HyphaParams params;
  Field field;
  unique_ptr<HyphaKynetics> kynetics;
  unique_ptr<Painter> painter;
  double energy;

  double takeEnergyFromField() {return field.consume(kynetics->getPos(), params.foodAmount) * params.foodToEnergyRatio;}
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
