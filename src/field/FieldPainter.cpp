//
//  FieldPainter.cpp
//  hyphae2App
//
//  Created by Nuno Godinho on 09/08/2020.
//

#include "FieldPainter.h"

FieldPainter::FieldPainter(const Field &_field) {
  field = &_field;
  image.allocate(field->getWidth(), field->getHeight(), OF_IMAGE_GRAYSCALE);
}

void FieldPainter::update() {
  for(auto y=0; y<field->getHeight(); y++) {
    for(auto x=0; x<field->getWidth(); x++) {
      float colorValue = 255 * field->getValue({ x, y });
      image.setColor(x, y, ofColor(colorValue));
    }
  }
  image.update();
}

void FieldPainter::draw() {
  image.draw(0,0);
}
