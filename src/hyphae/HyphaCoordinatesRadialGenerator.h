//
//  HyphaCoordinatesRadialGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#ifndef HyphaCoordinatesRadialGenerator_h
#define HyphaCoordinatesRadialGenerator_h

#include "IHyphaCoordinatesGenerator.h"
#include "ofMain.h"

class HyphaCoordinatesRadialGenerator: public IHyphaCoordinatesGenerator {
  glm::vec2 pos;
  int numRays;
  bool done = false;
  
  vector<HyphaCoordinates> get() override;

public:
  HyphaCoordinatesRadialGenerator(glm::vec2 pos, int numRays);
};

#endif /* HyphaCoordinatesRadialGenerator_h */
