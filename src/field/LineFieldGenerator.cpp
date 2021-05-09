//
//  LineFieldGenerator.cpp
//  rhizopusApp
//
//  Created by Nuno on 26/04/2021.
//

// Shapers inspired from here: https://forum.openframeworks.cc/t/non-linear-ofmap/13508

#include "LineFieldGenerator.h"
#include <glm/gtx/closest_point.hpp>

LineFieldGenerator::LineFieldGenerator(const double _maxThickness, const double _shaper)
: halfThickness(ofRandom(_maxThickness/4.0f, _maxThickness/2.0f))
, shaper(_shaper)
{
  calcRandomLine();
}

double LineFieldGenerator::getValue(const glm::vec2 normalizedPos) const {
  auto d = distanceToLine(normalizedPos);
  auto value = ofMap(d, 0, halfThickness, 1.0f, 0.0f, true);
  return shape(value);
}

double LineFieldGenerator::shape(const double value) const {
  return powf(value, this->shaper);
}

double LineFieldGenerator::distanceToLine(glm::vec2 point) const {
  auto closestPointOnLine = glm::closestPointOnLine(point, lineStart, lineEnd);
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

void LineFieldGenerator::calcRandomLine() {
  // Pick a start point
  lineStart = getRandomPerimeterPoint();
  // Pick an end point (which is not in the same side as the start point)
  do {
    lineEnd = getRandomPerimeterPoint();
  } while (lineStart.x == lineEnd.x || lineStart.y == lineEnd.y);
}
  
