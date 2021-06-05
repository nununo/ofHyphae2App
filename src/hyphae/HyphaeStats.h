//
//  HyphaeStats.h
//  rhizopusApp
//
//  Created by Nuno on 03/06/2021.
//

#ifndef HyphaeStats_h
#define HyphaeStats_h

struct HyphaeStats {
  int bornTotal;
  int deadTotal;
  int alive;
  int moved;
  int died;
  
  HyphaeStats(const int bornTotal, const int deadTotal, const int alive, const int moved, const int died);
};

#endif /* HyphaeStats_h */
