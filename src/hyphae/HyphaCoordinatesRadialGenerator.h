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
  glm::vec2 pos;
  vector<HyphaCoordinates> rays;
  int total;
  
  vector<HyphaCoordinates> get() override;
  
  vector<HyphaCoordinates> generateRays(int numRays);
  glm::vec2 getNewDirection();

public:
  HyphaCoordinatesRadialGenerator(shared_ptr<IField> field, glm::vec2 pos, int numRays, int total);
};

#endif /* HyphaCoordinatesRadialGenerator_h */
