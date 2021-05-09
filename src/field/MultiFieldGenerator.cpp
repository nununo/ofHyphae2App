//
//  MultiFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 05/05/2021.
//

#include "MultiFieldGenerator.h"

MultiFieldGenerator::MultiFieldGenerator(std::shared_ptr<IMultiFunc> _func): func(_func) {}

void MultiFieldGenerator::add(std::unique_ptr<IFieldGenerator> generator){
  generators.emplace_back(std::move(generator));
}

double MultiFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  vector<double> values;
  for(auto & generator : generators) {
    values.emplace_back(generator->getValue(normalizedPos));
  }
  return func->getValue(values);
}
