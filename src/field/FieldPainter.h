//
//  FieldPainter.h
//  hyphae2App
//
//  Created by Nuno Godinho on 09/08/2020.
//

#ifndef FieldPainter_h
#define FieldPainter_h

#include "IFieldPainter.h"

class FieldPainter: public IFieldPainter {
private:
  ofImage image;

public:
  FieldPainter(const glm::vec2 size);
  void draw(const IField &field) override;
};

#endif /* FieldPainter_h */
