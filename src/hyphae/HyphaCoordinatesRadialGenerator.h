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
  int numRays;
  
  vector<HyphaCoordinates> get() override;
  
  glm::vec2 getNewDirection();

public:
  HyphaCoordinatesRadialGenerator(shared_ptr<IField> field, glm::vec2 pos, int numRays);
};

#endif /* HyphaCoordinatesRadialGenerator_h */
