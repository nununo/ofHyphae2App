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

class Hypha {
  
private:
  const HyphaParams params;
  Field field;
  HyphaKynetics kynetics;
  double energy;
  int nextForkDistance;

  double eat();
  void updateEnergy();
  void throwForkEvent();
  void throwMovedEvent();
  void fork();
  int getNextForkDistance() const;

public:
  Hypha(const HyphaParams& _params, const Field& _field, const HyphaKynetics& kynetics, const double initialEnergy);
  void update();
  bool isAlive() const;
  HyphaKynetics getKynetics() const;

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaForkEventArgs> movedEvent;
};

#endif /* Hypha_h */
