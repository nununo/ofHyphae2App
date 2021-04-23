//
//  FieldPainter.cpp
//  hyphae2App
//
//  Created by Nuno Godinho on 09/08/2020.
//

#include "FieldPainter.h"

FieldPainter::FieldPainter(const IField *_field) {
  field = _field;
  image.allocate(field->getSize().x, field->getSize().y, OF_IMAGE_GRAYSCALE);
}

void FieldPainter::update() {
  for(auto y=0; y<field->getSize().y; y++) {
    for(auto x=0; x<field->getSize().x; x++) {
      float colorValue = 255 * field->getValue({ x, y });
      image.setColor(x, y, ofColor(colorValue));
    }
  }
  image.update();
}

void FieldPainter::draw() {
  image.draw(0,0);
}
