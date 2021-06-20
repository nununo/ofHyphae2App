//
//  FieldBuilderNoise.h
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#ifndef FieldBuilderNoise_h
#define FieldBuilderNoise_h

#include "IFieldBuilder.h"

class FieldBuilderNoise: public IFieldBuilder {
public:
  shared_ptr<IField> create(shared_ptr<FieldParams> params, const glm::vec2 size) const override;
};

#endif /* FieldBuilderNoise_h */
