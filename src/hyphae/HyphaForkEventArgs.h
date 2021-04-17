//
//  HyphaForkEventArgs.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkEventArgs_h
#define HyphaForkEventArgs_h

#include "ofMain.h"
#include "HyphaKynetics.h"

class HyphaForkEventArgs : public ofEventArgs {
  
public:
  const HyphaKynetics kynetics;
  
  HyphaForkEventArgs(const HyphaKynetics& _kynetics): kynetics(_kynetics) {}
};

#endif /* HyphaForkEventArgs_h */
