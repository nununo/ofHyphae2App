//
//  LineFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 26/04/2021.
//

// https://openframeworks.cc/documentation/math/ofMath/#show_ofLineSegmentIntersection
// http://paulbourke.net/geometry/pointlineplane/
// https://openframeworks.cc//documentation/glm/gtx_closest_point/#!show_glm::closestPointOnLine

#ifndef LineFieldGenerator_h
#define LineFieldGenerator_h

#include "IFieldGenerator.h"

class LineFieldGenerator: public IFieldGenerator {
private:
  struct StartEnd {
    glm::vec2 start;
    glm::vec2 end;
    double halfThickness;
  };
  
  vector<StartEnd> lines;
  double maxHalfThickness;
  double shaper;

  double distancePointToLine(glm::vec2 point, StartEnd line) const;
  glm::vec2 getRandomPerimeterPoint();
  StartEnd getRandomLine();
  double shape(const double value) const;

public:
  LineFieldGenerator(const int numLines, const double maxThickness, const double shaper);
  double getValue(const glm::vec2 normalizedPos) const override;
};

#endif /* LineFieldGenerator_h */
