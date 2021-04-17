//
//  Painter.cpp
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

// Mostly copied from the gl/textureBufferInstanceExample

#include "Painter.h"

Painter::Painter(const int maxSize, const ofColor _color) {
  color = _color;
  mesh.setMode(OF_PRIMITIVE_POINTS);
}

void Painter::add(glm::vec2 pos) {
  glm::vec3 pos3 = glm::vec3(pos, 0.f);
  mesh.addVertex(pos3);
}

void Painter::draw() {
  ofPushStyle();
  ofSetColor(color);
  ofFill();
  mesh.draw();
  ofPopStyle();
}
