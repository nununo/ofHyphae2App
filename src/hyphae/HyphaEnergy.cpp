//
//  HyphaEnergy.cpp
//  rhizopusApp
//
//  Created by Nuno on 23/04/2021.
//

#include "HyphaEnergy.h"

HyphaEnergy::HyphaEnergy(double initial, double _spendMoving)
: amount(initial)
, spendMoving(_spendMoving)
{}

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
