//
//  FieldBuilderLines.h
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#ifndef FieldBuilderLines_h
#define FieldBuilderLines_h

#include "IFieldBuilder.h"

class FieldBuilderLines: public IFieldBuilder {
public:
  shared_ptr<IField> create(shared_ptr<FieldParams> params, const glm::vec2 size) const override;
};

#endif /* FieldBuilderLines_h */
