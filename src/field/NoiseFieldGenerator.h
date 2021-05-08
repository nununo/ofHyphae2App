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
private:
  double getValue(const glm::vec2 normalizedPos) const override;
};
#endif /* NoiseFieldGenerator_h */