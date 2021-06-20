//
//  FieldBuilderAbundance.cpp
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#include "FieldBuilderNoise.h"
#include "NoiseFieldGenerator.h"
#include "WritableField.h"

std::shared_ptr<IField> FieldBuilderNoise::create(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto field = make_shared<WritableField>(size);
  field->generate(NoiseFieldGenerator());
  return field;
}
