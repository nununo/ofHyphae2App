//
//  NoiseFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#include "NoiseFieldGenerator.h"

double NoiseFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  return ofNormalize(ofNoise(normalizedPos) + ofNoise(normalizedPos*5),0,2);
}
