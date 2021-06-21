//
//  HyphaEnergy.cpp
//  rhizopusApp
//
//  Created by Nuno on 23/04/2021.
//

#include "HyphaEnergy.h"
#include "ofMain.h"

HyphaEnergy::HyphaEnergy(double initial, Range energySpentToMoveRange)
: amount{initial}
, spendMoving{calcEnergySpentToMove(energySpentToMoveRange)}
{}

/*
 We use a cubed random number so that the lows are much more probable than the highs. Then we map it in
 a way that the higher threshold is more probable than the lower threshold.
 */
double HyphaEnergy::calcEnergySpentToMove(Range energySpentToMoveInterval) {
  auto r = pow(ofRandom(1.0f), 3);
  return ofMap(r, 0, 1, energySpentToMoveInterval.max, energySpentToMoveInterval.min);
}

void HyphaEnergy::move() {
  amount = amount>spendMoving? amount-spendMoving : 0;
}

void HyphaEnergy::eat(double meal) {
  if (!isEmpty()) {
    amount = 1-amount>meal? amount+meal : 1;
  }
}

void HyphaEnergy::fork() {
  amount /= 2.0f;
}

bool HyphaEnergy::isEmpty() const {
  return amount == 0;
}

double HyphaEnergy::get() const {
  return amount;
}
