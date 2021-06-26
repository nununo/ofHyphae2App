//
//  ScreenOccupancy.h
//  rhizopusApp
//
//  Created by Nuno on 26/06/2021.
//

#ifndef ScreenOccupancy_h
#define ScreenOccupancy_h

#include "IOccupancy.h"

class ScreenOccupancy : public IOccupancy {
  const int sectorSideSize;
  const glm::vec2 size;
  ofPixels pixels;
  int cacheLifetime = 0;
  
  glm::vec2 convertFromScreen(const glm::vec2 pos) const;

  double getOccupancy(const glm::vec2 pos) const override;
  void update() override;
  void draw(const glm::vec2 pos, const glm::vec2 size) override;

public:
  ScreenOccupancy(const glm::vec2 size, const int sectorSideSize);
};
#endif /* ScreenOccupancy_h */
