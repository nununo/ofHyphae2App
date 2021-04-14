//
//  FieldPainter.h
//  hyphae2App
//
//  Created by Nuno Godinho on 09/08/2020.
//

#ifndef FieldPainter_h
#define FieldPainter_h

#include "Field.h"

class FieldPainter {
private:
  const Field *field;
  ofImage image;

public:
  FieldPainter(const Field *field);
  void update();
  void draw();
};

#endif /* FieldPainter_h */
