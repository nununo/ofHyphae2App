//
//  FieldPainter.h
//  hyphae2App
//
//  Created by Nuno Godinho on 09/08/2020.
//

#ifndef FieldPainter_h
#define FieldPainter_h

#include "IField.h"
#include "ofMain.h"

class FieldPainter {
private:
  const IField *field;
  ofImage image;

public:
  FieldPainter(const IField *field);
  void update();
  void draw();
};

#endif /* FieldPainter_h */
