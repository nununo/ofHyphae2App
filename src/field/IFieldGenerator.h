//
//  IFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#ifndef IFieldGenerator_h
#define IFieldGenerator_h

#include "ofMain.h"

class IFieldGenerator {
public:
  virtual ~IFieldGenerator() {};
  virtual double getValue(const glm::vec2 normalizedPos) const = 0;
};

#endif /* IFieldGenerator_h */
