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
#include "HyphaKynetics.h"
#include "HyphaForkEventArgs.h"

class Hypha {
  
private:
  const HyphaParams params;
  Field* const field;
  HyphaKynetics kynetics;
  double energy;
  int nextForkDistance;
  bool dead = false;

  double eat();
  void updateEnergy();
  void throwForkEvent();
  void throwMovedEvent();
  void fork();
  int getNextForkDistance() const;
  void updateDeadStatus();

public:
  Hypha(const HyphaParams& _params, Field *_field, const HyphaCoordinates coordinates, const double initialEnergy);
  void update();
  bool isAlive() const;

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaForkEventArgs> movedEvent;
};

#endif /* Hypha_h */
