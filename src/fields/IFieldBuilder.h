//
//  IFieldBuilder.h
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#ifndef IFieldBuilder_h
#define IFieldBuilder_h

#include "IField.h"
#include "FieldParams.h"

class IFieldBuilder {
public:
  virtual ~IFieldBuilder() {};
  virtual shared_ptr<IField> create(shared_ptr<FieldParams> params, const glm::vec2 size) const = 0;
};

#endif /* IFieldBuilder_h */
