//
//  ReadableField.cpp
//  rhizopusApp
//
//  Created by Nuno on 28/06/2021.
//

#include "ReadableField.h"

ReadableField::ReadableField(const glm::vec2 _size)
: size(_size)
{
  map.assign(size.y, vector<double>(size.x, 0));
}

double ReadableField::getValue(const glm::vec2 pos) const {
  return map[(int)pos.y][(int)pos.x];
}

glm::vec2 ReadableField::getSize() const {
  return size;
}

bool ReadableField::isInside(const glm::vec2 pos) const {
  return pos == glm::abs(pos) && pos.x <= size.x-1 && pos.y <= size.y-1;
}

void ReadableField::setValue(glm::vec2 pos, double newValue) {
  map[(int)pos.y][(int)pos.x] = ofClamp(newValue, 0.0f, 1.0f);
}
