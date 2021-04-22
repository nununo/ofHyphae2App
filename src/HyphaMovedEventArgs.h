//
//  HyphaMovedEventArgs.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaMovedEventArgs_h
#define HyphaMovedEventArgs_h

#include "ofMain.h"
#include "Hypha.h"

class HyphaMovedEventArgs : public ofEventArgs {
  
public:
  const glm::vec2 pos;
  
  HyphaMovedEventArgs(const glm::vec2 _pos): pos(_pos) {}
};

#endif /* HyphaForkEventArgs_h */
