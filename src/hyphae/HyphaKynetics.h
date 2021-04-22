//
//  HyphaKynetics.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef HyphaKynetics_h
#define HyphaKynetics_h

#include "HyphaParams.h"
#include "HyphaCoordinates.h"

class HyphaKynetics {
private:
  const HyphaParams params;
  const glm::vec2 fieldSize;
  HyphaCoordinates coordinates;
  glm::vec2 lastPixelPos;

  glm::vec2 nextDirection(const glm::vec2 _dir) const;

public:
  HyphaKynetics(const HyphaParams& _params, const HyphaCoordinates _coordinates, const glm::vec2 _fieldSize);
  glm::vec2 getPos() const;
  bool update();
  HyphaCoordinates getForkCoordinates();
  bool isInsideField();
};

#endif /* HyphaKinetics_h */
