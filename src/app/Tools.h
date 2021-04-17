//
//  Tools.h
//  hyphaeApp
//
//  Created by Nuno on 17/02/2019.
//

#ifndef Tools_h
#define Tools_h

#include "ofMain.h"

class Tools {
public:
  static int angleToInt(float angle);
  static float angleTo360(float angle);
  static float posToAngle(glm::vec2 v) {return  glm::angle(glm::vec2(1,0), v);}
  static float randomInRange(glm::vec2 v) {return ofRandom(v.x, v.y);}
  static float randomInSet(vector<float> set);
  static glm::vec2 getRandomVec2() {return glm::vec2(ofRandom(99999), ofRandom(99999));}
};

#endif /* Tools_h */
