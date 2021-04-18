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
  static int angleToInt(double angle);
  static double angleTo360(double angle);
  static double posToAngle(glm::vec2 v);
  static double randomInRange(glm::vec2 v);
  static double randomInSet(vector<double> set);
  static glm::vec2 getRandomVec2();
};

#endif /* Tools_h */
