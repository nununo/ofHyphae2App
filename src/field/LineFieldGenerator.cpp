//
//  LineFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 26/04/2021.
//

// Shapers inspired from here: https://forum.openframeworks.cc/t/non-linear-ofmap/13508

#include "LineFieldGenerator.h"
#include <glm/gtx/closest_point.hpp>

LineFieldGenerator::LineFieldGenerator(const int numPoints, const double _maxThickness, const double _shaper)
: maxHalfThickness(_maxThickness/2.0f)
, shaper(_shaper)
{
  for(auto i=0; i<numPoints;i++) {
    lines.push_back(getRandomLine());
  }
}

double LineFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  auto d = distancePointToLine(normalizedPos, lines[0]);
  auto value = ofMap(d, 0, lines[0].halfThickness, 1.0f, 0.0f, true);
  return shape(value);
}

double LineFieldGenerator::shape(const double value) const {
  return powf(value, this->shaper);
}

double LineFieldGenerator::distancePointToLine(glm::vec2 point, StartEnd line) const {
  auto closestPointOnLine = glm::closestPointOnLine(point, line.start, line.end);
  return ofClamp(abs(glm::distance(point, closestPointOnLine)), 0.0f, 1.0f);
}

glm::vec2 LineFieldGenerator::getRandomPerimeterPoint() {
  // First pick a random side
  // Then pick a random offset to move on that side
  // Finally build the perimeter point based on previous side and offset
  auto side = (int)ofRandom(4.0f);
  auto offset = ofRandom(1.0f);
  switch (side) {
    case 0:
      return {offset, 0};
      break;
    case 1:
      return {1, offset};
      break;
    case 2:
      return {offset, 1};
      break;
    default:
      return {0, offset};
      break;
  }
}

LineFieldGenerator::StartEnd LineFieldGenerator::getRandomLine() {
  StartEnd line;
  // Pick a start point
  line.start = getRandomPerimeterPoint();
  // Pick an end point (which is not in the same side as the start point)
  do {
    line.end = getRandomPerimeterPoint();
  } while (line.start.x == line.end.x || line.start.y == line.end.y);
  line.halfThickness = ofRandom(0.005f, maxHalfThickness);
  return line;
}
  
