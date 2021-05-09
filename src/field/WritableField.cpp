//
//  WritableField.cpp
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#include "WritableField.h"

WritableField::WritableField(const glm::vec2 _size)
: size(_size) {
  map.assign(size.x, vector<double>(size.y, 0));
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

void WritableField::generate(const std::shared_ptr<IFieldGenerator> generator) {
  for(auto y=0; y<size.y; y++) {
    for(auto x=0; x<size.x; x++) {
      setValue({x,y}, generator->getValue(normalize({x,y})));
    }
  }
}

double WritableField::consume(const glm::vec2 pos, const double amount) {
  auto value = getValue(pos);
  auto consumed = (value-amount>0? amount : value);
  setValue(pos, value-consumed);
  return consumed;
}
