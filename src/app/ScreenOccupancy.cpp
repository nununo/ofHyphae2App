//
//  ScreenOccupancy.cpp
//  rhizopusApp
//
//  Created by Nuno on 26/06/2021.
//

#include "ScreenOccupancy.h"

ScreenOccupancy::ScreenOccupancy(const glm::vec2 _size, const int _sectorSideSize)
: size{_size}
, sectorSideSize{_sectorSideSize}
{}

void ScreenOccupancy::update() {
  if (cacheLifetime-- <=0) {
    ofImage i;
    i.grabScreen(0, 0, size.x, size.y);
    i.setImageType(OF_IMAGE_GRAYSCALE);
    i.resize(glm::ceil(size.x/sectorSideSize), glm::ceil(size.y/sectorSideSize));
    ofPixels iPixels = i.getPixels();
    pixels.allocate(iPixels.getWidth(), iPixels.getHeight(), OF_IMAGE_GRAYSCALE);
    for(auto y=0; y<pixels.getHeight(); y++) {
      auto dymin = (y==0? 0 : -1);
      auto dymax = (y==pixels.getHeight()-1? 0 : 1);
      for(auto x=0; x<pixels.getWidth(); x++) {
        auto dxmin = (x==0? 0 : -1);
        auto dxmax = (x==pixels.getWidth()-1? 0 : 1);
        double maxOccupancy = 0;
        for(auto dy=dymin; dy<=dymax; dy++) {
          for(auto dx=-dxmin; dx<=dxmax; dx++) {
            auto occupancy = iPixels[iPixels.getPixelIndex(x+dx, y+dy)];
            if (occupancy > maxOccupancy) {
              maxOccupancy = occupancy;
            }
          }
        }
        pixels[pixels.getPixelIndex(x, y)] = maxOccupancy;
      }
    }
    cacheLifetime = 20;
  }
}

void ScreenOccupancy::draw(const glm::vec2 pos, const glm::vec2 size) {
  ofImage i(pixels);
  i.draw(pos.x, pos.y, size.x, size.y);
}


double ScreenOccupancy::getOccupancy(const glm::vec2 pos) const {
  if (pos.x<0 || pos.y<1 || pos.x>size.x-1 || pos.y>size.y-1) {
    return 0.0f;
  }
  auto pixelsPos = convertFromScreen(pos);
  int occupancy256 = pixels[pixels.getPixelIndex(pixelsPos.x, pixelsPos.y)];
  return ofMap(occupancy256, 240, 255, 1.0f, 0.0f, true);
}

glm::vec2 ScreenOccupancy::convertFromScreen(const glm::vec2 pos) const {
  return {glm::floor(pos.x/sectorSideSize), glm::floor(pos.y/sectorSideSize)};
}
