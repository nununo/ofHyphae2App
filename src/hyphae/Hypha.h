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
  std::shared_ptr<HyphaParams> params;
  HyphaKynetics kynetics;
  HyphaEnergy energy;
  int nextForkDistance;
  bool dead = false;

  double takeFoodFromField(IField &field);
  void throwForkEvent();
  void throwMovedEvent();
  void fork();
  int getNextForkDistance() const;
  void updateDeadStatus(IField &field);

public:
  Hypha(std::shared_ptr<HyphaParams> params, const HyphaCoordinates coordinates, const double initialEnergy);
  void update(IField &field);
  bool isAlive() const;

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaMovedEventArgs> movedEvent;
};

#endif /* Hypha_h */
