//
//  HyphaForkData.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkData_h
#define HyphaForkData_h

#include "ofMain.h"
#include "HyphaStatus.h"
#include "Hypha.h"

class HyphaForkData {
  
public:
  const HyphaCoordinates coordinates;
  const double energy;
  const HyphaStatus status;
  
  HyphaForkData(const HyphaCoordinates _coordinates, double _energy, HyphaStatus _status)
  : coordinates(_coordinates)
  , energy(_energy)
  , status(_status)
  {}
};

#endif /* HyphaForkData_h */
