//
//  HyphaePainter.cpp
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

// Mostly copied from the gl/textureBufferInstanceExample

#include "HyphaePainter.h"

HyphaePainter::HyphaePainter(const ofColor _color)
: color(_color)
{
  mesh.setMode(OF_PRIMITIVE_POINTS);
}

void HyphaePainter::draw(std::vector<glm::vec3> positions) {
  //mesh.clear();
  //mesh.addVertices(positions);
  ofPushStyle();
  ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
  ofSetColor(color);
  ofFill();
  //mesh.draw();
  for(auto& pos : positions) {
    ofDrawRectangle(pos.x, pos.y, 1, 1);
  }
  ofPopStyle();
}
