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
  auto noise1 = ofNoise(pos*1.5f); // pos*3
  noise1 = pow(noise1, 0.57f);
  noise1 = ofMap(noise1, 0.2f, 1.0f, 0.0f, 1.0f, true);
  return noise1;
}
