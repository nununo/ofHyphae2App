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
  auto noise = ofNoise(pos) + ofNoise(pos*4);
  noise = ofNormalize(noise, 0.2f, 1.7f);
  noise = pow(noise, 3);
  return noise;
}
