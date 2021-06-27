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
  int alive;
  int moved;
  int born;
  int died;
  double fertilityRatio;
  int lifetime;

  HyphaeStats(
    const int alive,
    const int moved,
    const int born,
    const int died,
    const double fertilityRatio,
    const int lifetime);
};

#endif /* HyphaeStats_h */
