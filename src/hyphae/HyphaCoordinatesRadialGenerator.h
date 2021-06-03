//
//  HyphaCoordinatesRadialGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#ifndef HyphaCoordinatesRadialGenerator_h
#define HyphaCoordinatesRadialGenerator_h

#include "IHyphaCoordinatesGenerator.h"
#include "IField.h"

class HyphaCoordinatesRadialGenerator: public IHyphaCoordinatesGenerator {
  shared_ptr<IField> field;
  double birthAreaRadius;
  glm::vec2 center;
  vector<HyphaCoordinates> rays;
  int total;
  
  vector<HyphaCoordinates> get() override;
  
  vector<HyphaCoordinates> generateRays(int numRays);
  HyphaCoordinates generateRay();
  glm::vec2 getNewOffset();
  glm::vec2 getNewPosition();
  glm::vec2 getNewInwardDirection(glm::vec2 pos);

public:
  HyphaCoordinatesRadialGenerator(shared_ptr<IField> field, glm::vec2 center, double birthAreaRadius, int numRays, int total);
};

#endif /* HyphaCoordinatesRadialGenerator_h */
