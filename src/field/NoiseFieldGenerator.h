//
//  NoiseFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#ifndef NoiseFieldGenerator_h
#define NoiseFieldGenerator_h

#include "IFieldGenerator.h"

class NoiseFieldGenerator: public IFieldGenerator {
  const double offset;
  double getValue(const glm::vec2 normalizedPos) const override;
public:
  NoiseFieldGenerator();
};
#endif /* NoiseFieldGenerator_h */
