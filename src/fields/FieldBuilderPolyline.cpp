//
//  FieldBuilderPolyline.cpp
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#include "FieldBuilderPolyline.h"
#include "PolylineFieldGenerator.h"
#include "WritableField.h"

std::shared_ptr<IField> FieldBuilderPolyline::create(std::shared_ptr<FieldParams> fieldParams, const glm::vec2 size) const {
  auto polylineGenerator = PolylineFieldGenerator(size, 20, 20);
  
  auto field = make_shared<WritableField>(size);
  field->generate(polylineGenerator);
  return field;
}
