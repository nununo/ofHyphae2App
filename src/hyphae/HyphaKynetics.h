//
//  HyphaKynetics.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef HyphaKynetics_h
#define HyphaKynetics_h

#include "HyphaParams.h"

class HyphaKynetics {
private:
  HyphaParams params;
  glm::vec2 pos;
  glm::vec2 dir;
  glm::vec2 delta = glm::vec2(0,0);
  bool posIsNewPixel = false;

  glm::vec2 nextDirection(const glm::vec2 _dir) const;

public:
  HyphaKynetics(const HyphaParams& _params, const glm::vec2 _pos, const glm::vec2 _dir);
  glm::vec2 getPos() {return pos;}
  void update();
  HyphaKynetics getForkKynetics();
};

#endif /* HyphaKinetics_h */
