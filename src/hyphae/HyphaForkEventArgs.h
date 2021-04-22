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
  
  HyphaForkEventArgs(const HyphaCoordinates _coordinates): coordinates(_coordinates) {}
};

#endif /* HyphaForkEventArgs_h */
