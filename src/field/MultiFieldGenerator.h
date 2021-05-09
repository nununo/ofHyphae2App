//
//  AverageFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 05/05/2021.
//

#ifndef MultiFieldGenerator_h
#define MultiFieldGenerator_h

#include "IFieldGenerator.h"
#include "IMultiFunc.h"

class MultiFieldGenerator: public IFieldGenerator {
private:
  vector<std::unique_ptr<IFieldGenerator>> generators;
  const std::shared_ptr<IMultiFunc> func;

  double getValue(const glm::vec2 normalizedPos) const override;

public:
  MultiFieldGenerator(std::shared_ptr<IMultiFunc> _func);
  void add(std::unique_ptr<IFieldGenerator> generator);
};

#endif /* MultiFieldGenerator_h */
