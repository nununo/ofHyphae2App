//
//  HyphaForkEventArgs.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkEventArgs_h
#define HyphaForkEventArgs_h

#include "ofMain.h"
#include "HyphaStatus.h"
#include "Hypha.h"

class HyphaForkEventArgs : public ofEventArgs {
  
public:
  const HyphaCoordinates coordinates;
  double energy;
  HyphaStatus status;
  
  HyphaForkEventArgs(const HyphaCoordinates _coordinates, double _energy, HyphaStatus _status)
  : coordinates(_coordinates)
  , energy(_energy)
  , status(_status)
  {}
};

#endif /* HyphaForkEventArgs_h */
