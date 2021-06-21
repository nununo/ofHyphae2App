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
  std::shared_ptr<const HyphaParams> params;
  HyphaKynetics kynetics;
  HyphaEnergy energy;
  int nextForkDistance;
  HyphaStatus status;

  double takeFoodFromField(IField &field);
  void throwForkEvent();
  void throwMovedEvent();
  void fork();
  int getNextForkDistance() const;
  HyphaStatus calcStatus(IField &field, HyphaStatus oldStatus) const;
  double getSpeed() const;
  bool move(IField &fieldx);

public:
  Hypha(std::shared_ptr<const HyphaParams> params, const HyphaCoordinates coordinates, const double initialEnergy, const HyphaStatus status);
  void update(IField &field, const bool allowForks);
  bool isAlive() const;
  glm::vec2 getPosition() const;

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaMovedEventArgs> movedEvent;
};

#endif /* Hypha_h */
