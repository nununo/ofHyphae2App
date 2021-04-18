//
//  Painter.cpp
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

// Mostly copied from the gl/textureBufferInstanceExample

#include "Painter.h"

Painter::Painter(const ofColor _color): color(_color) {}

void Painter::draw(std::vector<glm::vec2> positions) {
  ofPushStyle();
  ofSetColor(color);
  ofFill();
  for(auto& pos : positions) {
    ofDrawRectangle(pos.x, pos.y, 1, 1);
  }
  ofPopStyle();
}
