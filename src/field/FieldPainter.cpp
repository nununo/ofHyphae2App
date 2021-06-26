//
//  FieldPainter.cpp
//  hyphae2App
//
//  Created by Nuno Godinho on 09/08/2020.
//

#include "FieldPainter.h"

FieldPainter::FieldPainter(const glm::vec2 size)
{
  image.allocate(size.x, size.y, OF_IMAGE_GRAYSCALE);
}

void FieldPainter::draw(const IField &field) {
  for(auto y=0; y<field.getSize().y; y++) {
    for(auto x=0; x<field.getSize().x; x++) {
      double colorValue = 255 * field.getValue({x, y});
      image.setColor(x, y, ofColor(colorValue));
    }
  }
  image.update();
  image.draw(0,0);
}
