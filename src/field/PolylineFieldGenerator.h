//
//  PolylineFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#ifndef PolylineFieldGenerator_h
#define PolylineFieldGenerator_h

#include "IFieldGenerator.h"
#include "ofMain.h"

class PolylineFieldGenerator : public IFieldGenerator {
private:
  ofPixels map;
  
  ofPolyline generatePolyline(int numSegments);
  void drawPixels(ofPolyline &p, int width);

  double getValue(const glm::vec2 normalizedPos) const override;

public:
  PolylineFieldGenerator(glm::vec2 size, int numSegments, int width);
};

#endif /* PolylineFieldGenerator_h */
