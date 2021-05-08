//
//  AverageFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 05/05/2021.
//

#ifndef AverageFieldGenerator_h
#define AverageFieldGenerator_h

#include <vector>
#include "IFieldGenerator.h"

class AverageFieldGenerator: public IFieldGenerator {
private:
  vector<std::unique_ptr<IFieldGenerator>> generators;

  double getValue(const glm::vec2 normalizedPos) const override;

public:
  void add(std::unique_ptr<IFieldGenerator> generator);
};

#endif /* AverageFieldGenerator_h */
