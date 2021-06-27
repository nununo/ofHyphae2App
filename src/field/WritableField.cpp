//
//  WritableField.cpp
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#include "WritableField.h"

WritableField::WritableField(const glm::vec2 _size)
: size(_size)
{
  map.assign(size.y, vector<double>(size.x, 0));
}

double WritableField::getValue(const glm::vec2 pos) const {
  return map[(int)pos.y][(int)pos.x];
}

glm::vec2 WritableField::getSize() const {
  return size;
}

void WritableField::setValue(glm::vec2 pos, double newValue) {
  map[(int)pos.y][(int)pos.x] = ofClamp(newValue, 0.0f, 1.0f);
}

glm::vec2 WritableField::normalize(const glm::vec2 pos) const {
  auto normx = ofNormalize(pos.x, 0, size.x);
  auto normy = ofNormalize(pos.y, 0, size.y);
  return {normx, normy};
}

void WritableField::generate(const IFieldGenerator& generator) {
  for(auto y=0; y<size.y; y++) {
    for(auto x=0; x<size.x; x++) {
      setValue({x,y}, generator.getValue(normalize({x,y})));
    }
  }
}

bool WritableField::isInside(const glm::vec2 pos) const {
  return pos == glm::abs(pos) && pos.x <= size.x-1 && pos.y <= size.y-1;
}

bool WritableField::hasEnoughFoodAtPosition(glm::vec2 pos) const {
  double food = 0;
  double pixels = 0;
  for (auto y=pos.y-100; y<pos.y+100; y++) {
    for (auto x=-100; x<100; x++) {
      if (y>0 && x>0) {
        pixels++;
        food += getValue({x,y});
      }
    }
  }
  ofLog() << "food at birth position: " << ofToString(food/pixels);
  return food/pixels > 0.5;
}
