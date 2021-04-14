//
//  Hypha.cpp
//  rhizopusApp
//
//  Created by Nuno on 13/04/2021.
//

#include "Hypha.h"

Hypha::Hypha(const Field *_field, const glm::vec2 _pos, const glm::vec2 _dir, const float _energy) {
  pos = _pos;
  dir = _dir;
  energy = ofClamp(_energy, 0, 1);
  field = _field;
  painter.reset(new Painter(1, ofColor::red));
}

void Hypha::update() {
  pos += dir;
  painter->clear();
  painter->add(pos);
}

void Hypha::draw() {
  painter->draw();
}
