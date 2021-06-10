//
//  FieldBuilderLines.cpp
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#include "FieldBuilderLines.h"
#include "NoiseFieldGenerator.h"
#include "MultiFieldGenerator.h"
#include "MaxFunc.h"
#include "MinFunc.h"
#include "ThresholdFieldGenerator.h"
#include "LineFieldGenerator.h"
#include "WritableField.h"

std::shared_ptr<IField> FieldBuilderLines::create(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto noise = std::make_unique<NoiseFieldGenerator>();
  auto thresholdNoise = std::make_unique<ThresholdFieldGenerator>(std::move(noise), fieldParams->zeroThreshold);
  
  auto lines = std::make_unique<MultiFieldGenerator>(std::make_shared<MaxFunc>());
  for(auto i=0; i<3; i++) { // TODO
    lines->add(std::make_unique<LineFieldGenerator>(200/size.x, 1)); // TODO
  }
  
  auto interception = MultiFieldGenerator(make_shared<MinFunc>());
  interception.add(move(lines));
  interception.add(move(thresholdNoise));
  
  auto field = make_shared<WritableField>(size);
  field->generate(interception);
  return field;
}
