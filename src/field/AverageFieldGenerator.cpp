//
//  AverageFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 05/05/2021.
//

#include "AverageFieldGenerator.h"

void AverageFieldGenerator::add(std::unique_ptr<IFieldGenerator> generator){
  generators.push_back(std::move(generator));
}

double AverageFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  double total = 0;
  for(auto & generator : generators) {
    total += generator->getValue(normalizedPos);
  }
  return total / generators.size();
}
