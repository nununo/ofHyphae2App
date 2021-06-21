//
//  HyphaCoordinatesLeftRightGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#ifndef HyphaCoordinatesLeftRightGenerator_h
#define HyphaCoordinatesLeftRightGenerator_h

#include "IHyphaCoordinatesGenerator.h"
#include "IField.h"

class HyphaCoordinatesLeftRightGenerator: public IHyphaCoordinatesGenerator {
  glm::vec2 center;
  int total;
  
  vector<HyphaCoordinates> get() override;

public:
  HyphaCoordinatesLeftRightGenerator(glm::vec2 center, int total);
};

#endif /* HyphaCoordinatesLeftRightGenerator_h */
