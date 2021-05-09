//
//  ThresholdFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#ifndef ThresholdFieldGenerator_h
#define ThresholdFieldGenerator_h

#include "IFieldGenerator.h"

class ThresholdFieldGenerator: public IFieldGenerator {
private:
  const double threshold;
  std::unique_ptr<IFieldGenerator> generator;
  double getValue(const glm::vec2 normalizedPos) const override;

public:
  ThresholdFieldGenerator(std::unique_ptr<IFieldGenerator> generator, const double threshold);
};

#endif /* ThresholdFieldGenerator_h */
