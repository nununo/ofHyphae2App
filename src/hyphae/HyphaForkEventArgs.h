//
//  HyphaForkEventArgs.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkEventArgs_h
#define HyphaForkEventArgs_h

#include "ofMain.h"
#include "Hypha.h"

class HyphaForkEventArgs : public ofEventArgs {
  
public:
  const HyphaCoordinates coordinates;
  double energy;
  
  HyphaForkEventArgs(const HyphaCoordinates _coordinates, double _energy)
  : coordinates(_coordinates)
  , energy(_energy) {}
};

#endif /* HyphaForkEventArgs_h */
