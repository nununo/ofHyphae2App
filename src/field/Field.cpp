//
//  Field.cpp
//  hyphae2App
//
//  Created by Nuno Godinho on 03/08/2020.
//

#include "Field.h"

Field::Field(const FieldParams& _params, const int width, const int height): params(_params) {
  map.assign(height, vector<double>(width, 0));
  populate();
}

glm::vec2 Field::normalize(const glm::vec2 pos) const {
  auto normx = ofNormalize(pos.x, 0, getWidth());
  auto normy = ofNormalize(pos.y, 0, getHeight());
  return {normx, normy};
}

void Field::populate() {
  for(auto y=0; y<getHeight(); y++) {
    for(auto x=0; x<getWidth(); x++) {
      map[y][x] = calcFoodAtPosition(x,y);
    }
  }
}

double Field::calcFoodAtPosition(const int x, const int y) const {
  auto normalizedPos = normalize({x,y});
  auto beforeThreshold = ofNormalize(ofNoise(normalizedPos) + ofNoise(normalizedPos*5),0,2);
  auto afterThreshold = (beforeThreshold>params.zeroThreshold? beforeThreshold : 0);
  return ofMap(afterThreshold, params.zeroThreshold, 1.0f, 0.0f, 1.0f);
  return ;
}

double Field::consume(const glm::vec2 pos, const double amount) {
  auto value = getValue(pos);
  auto consumed = (value-amount>0? amount : value);
  setValue(pos, value-consumed);
  return consumed;
}
