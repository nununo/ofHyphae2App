//
//  HyphaForkData.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkData_h
#define HyphaForkData_h

#include "ofMain.h"
#include "Hypha.h"

class HyphaForkData {
  
public:
  const HyphaCoordinates coordinates;
  const double energy;
  
  HyphaForkData(const HyphaCoordinates _coordinates, double _energy)
  : coordinates(_coordinates)
  , energy(_energy)
  {}
};

#endif /* HyphaForkData_h */
