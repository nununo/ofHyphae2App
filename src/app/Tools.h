//
//  Tools.h
//  hyphaeApp
//
//  Created by Nuno on 17/02/2019.
//

#ifndef Tools_h
#define Tools_h

#include "ofMain.h"
#include "Range.h"
#include "RangeRange.h"

class Tools {
public:
  static int angleToInt(double angle);
  static double angleTo360(double angle);
  static double posToAngle(glm::vec2 v);
  static double randomInRange(Range r);
  static Range randomInRangeRange(RangeRange rr);
  static double randomInSet(vector<double> set);
  static glm::vec2 getRandomVec2();
  static Range toRadians(Range degrees);
  static bool tamperedCoinToss(double probability);
};

#endif /* Tools_h */
