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
  const double maxAngle;
  vector<HyphaCoordinates> directions;
  int total;
  
  vector<HyphaCoordinates> get() override;
  
  vector<HyphaCoordinates> generateDirections(int numDirections);
  HyphaCoordinates generateDirection() const;
  glm::vec2 getNewPosition() const;
  glm::vec2 getNewDirection() const;

public:
  HyphaCoordinatesRadialGenerator(const double maxAngle, const int numDirections, const int total);
};

#endif /* HyphaCoordinatesRadialGenerator_h */
