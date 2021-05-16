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
  shared_ptr<HyphaParams> params;
  HyphaCoordinates coordinates;
  glm::vec2 lastPixelPos;

  glm::vec2 nextDirection(const glm::vec2 _dir) const;

public:
  HyphaKynetics(shared_ptr<HyphaParams> params, const HyphaCoordinates coordinates);
  bool update();
  glm::vec2 getPixelPos() const;
  HyphaCoordinates getForkCoordinates();
  bool isInsideField(const glm::vec2 fieldSize);
};

#endif /* HyphaKinetics_h */
