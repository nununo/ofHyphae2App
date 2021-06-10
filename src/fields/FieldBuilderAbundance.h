//
//  FieldBuilderAbundance.h
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#ifndef FieldBuilderAbundance_h
#define FieldBuilderAbundance_h

#include "IFieldBuilder.h"

class FieldBuilderAbundance: public IFieldBuilder {
public:
  shared_ptr<IField> create(shared_ptr<FieldParams> params, const glm::vec2 size) const override;
};

#endif /* FieldBuilderAbundance_h */
