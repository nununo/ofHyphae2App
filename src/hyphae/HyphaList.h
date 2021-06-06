//
//  HyphaList.h
//  rhizopusApp
//
//  Created by Nuno on 05/06/2021.
//

#include "Hypha.h"

#ifndef HyphaList_h
#define HyphaList_h

class HyphaList: public list<Hypha> {
  void sortByDistanceToPoint(glm::vec2 point);
  double getPercentageThresholdRadius(double percentage);

public:
  glm::vec2 getCenterOfMass() const;
  double getDensity(double percentage);
};

#endif /* HyphaList_h */
