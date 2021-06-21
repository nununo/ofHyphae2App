//
//  HyphaCoordinates.h
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#ifndef HyphaCoordinates_h
#define HyphaCoordinates_h

#include "ofMain.h"

class HyphaCoordinates {
public:
  glm::vec2 pos;
  const glm::vec2 originalDir;
  glm::vec2 dir;
  
  HyphaCoordinates(const glm::vec2 _pos, const glm::vec2 _dir)
  :pos(_pos)
  ,dir(_dir)
  ,originalDir(_dir)
  {}
};

inline std::ostream& operator<<(std::ostream &strm, const HyphaCoordinates &hc) {
  return strm << "HC( " << hc.pos << " , " << hc.dir << " )";
}
#endif /* HyphaCoordinates_h */
