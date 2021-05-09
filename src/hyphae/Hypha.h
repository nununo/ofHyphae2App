//
//  Hypha.h
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#ifndef Hypha_h
#define Hypha_h

#include "IField.h"
#include "HyphaParams.h"
#include "HyphaKynetics.h"
#include "HyphaEnergy.h"
#include "HyphaForkEventArgs.h"
#include "HyphaMovedEventArgs.h"

class Hypha {
  
private:
  const HyphaParams params;
  std::shared_ptr<IField>  field;
  HyphaKynetics kynetics;
  HyphaEnergy energy;
  int nextForkDistance;
  bool dead = false;

  double takeFoodFromField();
  void throwForkEvent();
  void throwMovedEvent();
  void fork();
  int getNextForkDistance() const;
  void updateDeadStatus();

public:
  Hypha(const HyphaParams& _params, std::shared_ptr<IField> _field, const HyphaCoordinates coordinates, const double initialEnergy);
  void update();
  bool isAlive() const;

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaMovedEventArgs> movedEvent;
};

#endif /* Hypha_h */
