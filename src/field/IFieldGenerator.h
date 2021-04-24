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
  virtual double getValue(glm::vec2 pos) const = 0;
};

#endif /* IFieldGenerator_h */
