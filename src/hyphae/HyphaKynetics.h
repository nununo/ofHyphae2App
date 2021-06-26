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
  shared_ptr<const HyphaParams> params;
  HyphaCoordinates coordinates;
  glm::vec2 lastPixelPos;
  double cachedAngleWithOriginaDirection;
  int cacheLifetime = 0;

  glm::vec2 nextDirection(const glm::vec2 _dir) const;
  void updateAngleWithOriginalDirection();

public:
  HyphaKynetics(shared_ptr<const HyphaParams> params, const HyphaCoordinates coordinates);
  bool update(double speed);
  glm::vec2 getPixelPos() const;
  HyphaCoordinates getForkCoordinates();
  double angleWithOriginalDirection() const;
};

#endif /* HyphaKinetics_h */
