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
  double shaper;
  glm::vec2 lineStart;
  glm::vec2 lineEnd;
  double halfThickness;

  double distanceToLine(glm::vec2 point) const;
  glm::vec2 getRandomPerimeterPoint();
  void calcRandomLine();
  double shape(const double value) const;

public:
  LineFieldGenerator(const double maxThickness, const double shaper);
  double getValue(const glm::vec2 normalizedPos) const override;
};

#endif /* LineFieldGenerator_h */
