//
//  FieldBuilderPolyline.h
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#ifndef FieldWithPolyline_h
#define FieldWithPolyline_h

#include "IFieldBuilder.h"

class FieldBuilderPolyline: public IFieldBuilder {
public:
  shared_ptr<IField> create(shared_ptr<FieldParams> params, const glm::vec2 size) const override;
};

#endif /* FieldBuilderPolyline */
