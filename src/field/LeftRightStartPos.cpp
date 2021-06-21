//
//  LeftRightStartPos.cpp
//  rhizopusApp
//
//  Created by Nuno on 19/06/2021.
//

#include "LeftRightStartPos.h"

LeftRightStartPos::LeftRightStartPos(std::shared_ptr<IField> _field, const int _probeSize)
: field(_field)
, probeSize(_probeSize)
{}

glm::vec2 LeftRightStartPos::get() const {
  double leftSum = 0;
  double rightSum = 0;
  glm::vec2 leftStart = {0, field->getSize().y/2-probeSize/2};
  glm::vec2 rightStart = {field->getSize().x-probeSize, field->getSize().y/2-probeSize/2};
  for(auto y=0; y<probeSize; y++) {
    for(auto x=0; x<probeSize; x++) {
      leftSum += field->getValue(leftStart + glm::vec2(x,y));
      rightSum += field->getValue(rightStart + glm::vec2(x,y));
    }
  }
  auto pos = (leftSum > rightSum? glm::vec2(0, field->getSize().y/2) : glm::vec2(field->getSize().x, field->getSize().y/2));
  ofLog() << "startPos: " << pos;
  return pos;
}
