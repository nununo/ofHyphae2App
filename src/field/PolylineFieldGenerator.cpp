//
//  PolylineFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#include "PolylineFieldGenerator.h"

PolylineFieldGenerator::PolylineFieldGenerator(glm::vec2 size, int numSegments, int width) {
  map.allocate(size.x, size.y, OF_IMAGE_GRAYSCALE);
  auto p = generatePolyline(numSegments);
  drawPixels(p, width);
}

ofPolyline PolylineFieldGenerator::generatePolyline(int numSegments) {
  ofPolyline p;
  for(auto i=0; i<numSegments; i++) {
    p.lineTo(ofRandom(map.getWidth()), ofRandom(map.getHeight()));
  }
  p.close();
  return p;
}

void PolylineFieldGenerator::drawPixels(ofPolyline &p, int width) {
  ofFbo fbo;
  
  fbo.allocate(map.getWidth(), map.getHeight(), GL_RGB);
  fbo.begin();
  ofClear(ofColor::white);
  ofSetColor(ofColor::black);
  ofSetLineWidth(width);
  p.draw();
  fbo.end();
  fbo.readToPixels(map);
}

double PolylineFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  glm::vec2 pos = {
    ofMap(normalizedPos.x, 0, 1, 0, map.getWidth()),
    ofMap(normalizedPos.y, 0, 1, 0, map.getHeight())
  };
  return map.getColor(pos.x, pos.y).r;
}
