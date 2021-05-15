//
//  IHyphaCoordinatesGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#ifndef IHyphaCoordinatesGenerator_h
#define IHyphaCoordinatesGenerator_h

#include "HyphaCoordinates.h"

class IHyphaCoordinatesGenerator {
public:
  virtual ~IHyphaCoordinatesGenerator() {};
  virtual vector<HyphaCoordinates> get() = 0;
};

#endif /* IHyphaCoordinatesGenerator_h */
