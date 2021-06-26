//
//  IOccupancy.h
//  rhizopusApp
//
//  Created by Nuno on 26/06/2021.
//

#ifndef IOccupancy_h
#define IOccupancy_h

#include "ofMain.h"

class IOccupancy {
public:
  virtual double getOccupancy(const glm::vec2 pos) const = 0;
  virtual void update() = 0;
  virtual void draw(const glm::vec2 pos, const glm::vec2 size) = 0;
};

#endif /* IOccupancy_h */
