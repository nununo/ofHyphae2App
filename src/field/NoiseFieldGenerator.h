//
//  NoiseFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#ifndef NoiseFieldGenerator_h
#define NoiseFieldGenerator_h

#include "IFieldGenerator.h"
#include "FieldParams.h"

class NoiseFieldGenerator: public IFieldGenerator {
  shared_ptr<const FieldParams> params;
  const double offset;
  
  double getValue(const glm::vec2 normalizedPos) const override;

public:
  NoiseFieldGenerator(shared_ptr<const FieldParams> params);
};
#endif /* NoiseFieldGenerator_h */
