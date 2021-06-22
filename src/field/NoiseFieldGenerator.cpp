//
//  NoiseFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#include "NoiseFieldGenerator.h"

NoiseFieldGenerator::NoiseFieldGenerator()
: offset(ofRandom(1000.0f))
{}

double NoiseFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  glm::vec2 pos = {normalizedPos.x + offset, normalizedPos.y + offset};
  auto noise = ofNoise(pos); // pos*3
  noise = pow(noise, 2);
  noise = ofNormalize(noise, 0.3f, 0.4f);
  return noise;
}
