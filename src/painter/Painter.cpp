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
  ofVboMesh mesh;
  mesh.setMode(OF_PRIMITIVE_POINTS);
  for(auto& pos : positions) {
    mesh.addVertex(glm::vec3(pos, 0.f));
  }

  ofPushStyle();
  ofSetColor(color);
  ofFill();
  mesh.draw();
  ofPopStyle();
}
