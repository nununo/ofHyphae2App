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
, offset{_offset.x+0.5f, _offset.y}
, blendMode{_blendMode}
{}

void HyphaePainter::draw(std::vector<glm::vec3> positions) {
  mesh.clear();
  mesh.addVertices(positions);
  ofPushView();
  ofTranslate(offset);
  ofPushStyle();
  ofEnableBlendMode(blendMode);
  ofSetColor(color);
  ofFill();
  mesh.drawVertices();
  ofPopStyle();
  ofPopView();
}
