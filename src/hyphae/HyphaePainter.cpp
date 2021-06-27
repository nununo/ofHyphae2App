//
//  HyphaePainter.cpp
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

// Mostly copied from the gl/textureBufferInstanceExample

#include "HyphaePainter.h"

HyphaePainter::HyphaePainter(const ofColor _color, glm::vec2 _offset, const ofBlendMode _blendMode)
: color{_color}
, offset{_offset}
, blendMode{_blendMode}
{
  mesh.setMode(OF_PRIMITIVE_POINTS);
}

void HyphaePainter::draw(std::vector<glm::vec3> positions) {
  //mesh.clear();
  //mesh.addVertices(positions);
  ofPushView();
  ofTranslate(offset);
  ofPushStyle();
  ofEnableBlendMode(blendMode);
  ofSetColor(color);
  ofFill();
  //mesh.draw();
  for(auto& pos : positions) {
    ofDrawRectangle(pos.x, pos.y, 1, 1);
  }
  ofPopStyle();
  ofPopView();
}
