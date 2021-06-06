//
//  HyphaeStats.h
//  rhizopusApp
//
//  Created by Nuno on 03/06/2021.
//

#ifndef HyphaeStats_h
#define HyphaeStats_h

#include "ofMain.h"

struct HyphaeStats {
  int bornTotal;
  int deadTotal;
  int moved;
  int born;
  int died;
  double growthPercentage;
  double density;
  glm::vec2 centerOfMass;

  HyphaeStats(
    const int bornTotal,
    const int deadTotal,
    const int moved,
    const int born,
    const int died,
    const glm::vec2 centerOfMass,
    const double density);
};

#endif /* HyphaeStats_h */
