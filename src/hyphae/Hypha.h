//
//  Hypha.h
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#ifndef Hypha_h
#define Hypha_h

#include "Field.h"
#include "HyphaParams.h"
#include "HyphaForkEventArgs.h"
#include "HyphaKynetics.h"
#include "Painter.h"

class Hypha {
  
private:
  const HyphaParams params;
  Field field;
  HyphaKynetics kynetics;
  double energy;

  double eat();
  void updateEnergy();
  void throwForkEvent();

public:
  Hypha(const HyphaParams& _params, const Field& _field, const HyphaKynetics& kynetics, const double initialEnergy);
  void update();
  bool isAlive() const {return energy>0;}
  void paint(Painter *painter);

  ofEvent<HyphaForkEventArgs> forkEvent;
};

#endif /* Hypha_h */
