//
//  HyphaEnergy.h
//  rhizopusApp
//
//  Created by Nuno on 23/04/2021.
//

#ifndef HyphaEnergy_h
#define HyphaEnergy_h

class HyphaEnergy {
private:
  double amount;
  const double spendMoving;

public:
  HyphaEnergy(double initial, double spendMoving);
  void move();
  void eat(double meal);
  void fork();
  bool isEmpty() const;
  double get() const;
};
#endif /* HyphaEnergy_h */
