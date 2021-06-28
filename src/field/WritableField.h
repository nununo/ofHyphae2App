//
//  WritableField.h
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#ifndef WritableField_h
#define WritableField_h

#include "ReadableField.h"
#include "IFieldGenerator.h"

class WritableField: public ReadableField {
private:
  glm::vec2 normalize(const glm::vec2 pos) const;

public:
  WritableField(const glm::vec2 size, const int rightTolerance);
  void generate(const IFieldGenerator& generator);
  bool hasEnoughFoodAtPosition(const glm::vec2 pos) const override;
};

#endif /* WritableField_h */
