//
//  Field.cpp
//  hyphae2App
//
//  Created by Nuno Godinho on 03/08/2020.
//

#include "Field.h"

Field::Field(const int width, const int height) {
  map.assign(height, vector<float>(width, 0));
  populate();
}

glm::vec2 Field::normalize(const glm::vec2 pos) const {
  float normx = ofNormalize(pos.x, 0, getWidth());
  float normy = ofNormalize(pos.y, 0, getHeight());
  return {normx, normy};
}

void Field::populate() {
  for(auto y=0; y<getHeight(); y++) {
    for(auto x=0; x<getWidth(); x++) {
      map[y][x] = calcFoodAtPosition(x,y);
    }
  }
}

float Field::calcFoodAtPosition(const int x, const int y) const {
  glm::vec2 normalizedPos = normalize({x,y});
  return ofNormalize(ofNoise(normalizedPos) + ofNoise(normalizedPos*5),0,2);
}


float Field::consume(const glm::vec2 pos, const float diff) {
  float value = getValue(pos);
  value = (value-diff>0? value-diff : 0);
  setValue(pos, value);
  return value;
}
