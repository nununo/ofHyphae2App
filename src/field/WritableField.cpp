//
//  WritableField.cpp
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#include "WritableField.h"

WritableField::WritableField(const glm::vec2 size, const int rightTolerance)
: ReadableField(size)
{
  setRightTolerance(rightTolerance);
}

glm::vec2 WritableField::normalize(const glm::vec2 pos) const {
  auto normx = ofNormalize(pos.x, 0, getSize().x);
  auto normy = ofNormalize(pos.y, 0, getSize().y);
  return {normx, normy};
}

void WritableField::generate(const IFieldGenerator& generator) {
  for(auto y=0; y<getSize().y; y++) {
    for(auto x=0; x<getSize().x; x++) {
      setValue({x,y}, generator.getValue(normalize({x,y})));
    }
  }
}

bool WritableField::hasEnoughFoodAtPosition(const glm::vec2 pos) const {
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
  return food/pixels > 0.5; // TODO
}
