//
//  NoiseField.cpp
//  hyphae2App
//
//  Created by Nuno Godinho on 03/08/2020.
//

#include "NoiseField.h"

NoiseField::NoiseField(const FieldParams& _params, const glm::vec2 _size)
: params(_params)
, size(_size) {
  map.assign(size.x, vector<double>(size.y, 0));
  populate();
}

void NoiseField::setValue( glm::vec2 pos, double newValue) {
  map[(int)pos.y][(int)pos.x] = (newValue>0? newValue : 0);
}

double NoiseField::getValue(const glm::vec2 pos) const {
  return map[(int)pos.y][(int)pos.x];
}

glm::vec2 NoiseField::getSize() const {
  return size;
}

glm::vec2 NoiseField::normalize(const glm::vec2 pos) const {
  auto normx = ofNormalize(pos.x, 0, size.x);
  auto normy = ofNormalize(pos.y, 0, size.y);
  return {normx, normy};
}

void NoiseField::populate() {
  for(auto y=0; y<size.y; y++) {
    for(auto x=0; x<size.x; x++) {
      map[y][x] = calcFoodAtPosition(x,y);
    }
  }
}

double NoiseField::calcFoodAtPosition(const int x, const int y) const {
  auto normalizedPos = normalize({x,y});
  auto beforeThreshold = ofNormalize(ofNoise(normalizedPos) + ofNoise(normalizedPos*5),0,2);
  auto afterThreshold = (beforeThreshold>params.zeroThreshold? beforeThreshold : 0);
  return afterThreshold>0? ofMap(afterThreshold, params.zeroThreshold, 1.0f, 0.0f, 1.0f) : 0.0f;
}

double NoiseField::consume(const glm::vec2 pos, const double amount) {
  auto value = getValue(pos);
  auto consumed = (value-amount>0? amount : value);
  setValue(pos, value-consumed);
  return consumed;
}
