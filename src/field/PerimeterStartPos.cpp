//
//  PerimeterStartPos.cpp
//  rhizopusApp
//
//  Created by Nuno on 09/05/2021.
//

#include "PerimeterStartPos.h"

PerimeterStartPos::PerimeterStartPos(std::shared_ptr<IField> _field, int _areaSize)
: field(_field)
, areaSize(_areaSize)
{}

glm::vec2 PerimeterStartPos::linearTo2D(int linearPos) const {
  auto size = field->getSize();
  glm::vec2 pos;
  if (linearPos < size.x-1) {
    // Top side
    pos = {linearPos,0};
  } else if (linearPos < size.x+size.y-2) {
    // Right side
    pos = {size.x-1, linearPos-size.x+1};
  } else if (linearPos < 2*size.x+size.y-3) {
    // Bottom side
    pos = {2*size.x+size.y-linearPos-3, size.y-1};
  } else {
    // Left side
    pos = {0, 2*size.x+2*size.y-linearPos-4};
  }
  return pos;
}

glm::vec2 PerimeterStartPos::get() const {
  double highestValue = 0;
  int highestAreaFirstLinearPos = 0;
  int perimeter = 2*field->getSize().x + 2*field->getSize().y - 3;
  
  double areaValue = 0;
  for (auto linearPos=0; linearPos<perimeter; linearPos++) {
    auto pos = linearTo2D(linearPos);
    // Reset if in a new area
    if (linearPos % areaSize == 0) {
      if (areaValue>highestValue) {
        highestValue = areaValue;
        highestAreaFirstLinearPos = linearPos;
      }
      areaValue = 0;
    }
    areaValue += field->getValue(pos);
  }
  auto highestAreaMiddleLinearPos = highestAreaFirstLinearPos + (int)(areaSize/2);
  return linearTo2D(highestAreaMiddleLinearPos);
}
