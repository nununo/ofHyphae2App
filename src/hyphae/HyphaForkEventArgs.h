//
//  HyphaForkEventArgs.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkEventArgs_h
#define HyphaForkEventArgs_h

#include "ofMain.h"

class HyphaForkEventArgs : public ofEventArgs {
  
public:
  const glm::vec2 pos;
  const float angle;
  
  HyphaForkEventArgs(const glm::vec2 _pos, const float _angle)
  : pos(_pos)
  , angle(_angle)
  {}
};

#endif /* HyphaForkEventArgs_h */
