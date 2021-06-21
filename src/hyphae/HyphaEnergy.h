//
//  HyphaEnergy.h
//  rhizopusApp
//
//  Created by Nuno on 23/04/2021.
//

#ifndef HyphaEnergy_h
#define HyphaEnergy_h

#include "Range.h"

class HyphaEnergy {
private:
  double amount;
  const double spendMoving;

  double calcEnergySpentToMove(Range energySpentToMoveRange);

public:
  HyphaEnergy(double initial, Range energySpentToMoveRange);
  void move();
  void eat(double meal);
  void fork();
  bool isEmpty() const;
  double get() const;
};
#endif /* HyphaEnergy_h */
