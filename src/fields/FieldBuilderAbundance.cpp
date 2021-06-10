//
//  FieldBuilderAbundance.cpp
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#include "FieldBuilderAbundance.h"
#include "AbundanceFieldGenerator.h"
#include "WritableField.h"

std::shared_ptr<IField> FieldBuilderAbundance::create(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto field = make_shared<WritableField>(size);
  field->generate(AbundanceFieldGenerator());
  return field;
}
