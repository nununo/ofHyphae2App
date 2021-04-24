//
//  ThresholdFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#include "ThresholdFieldGenerator.h"

ThresholdFieldGenerator::ThresholdFieldGenerator(const IFieldGenerator *_generator, const double _threshold)
: generator(_generator)
, threshold(_threshold)
{}

double ThresholdFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  auto value = generator->getValue(normalizedPos);
  auto thresholded = (value>threshold? value : 0);
  return thresholded>0? ofMap(thresholded, threshold, 1.0f, 0.0f, 1.0f) : 0.0f;
}

