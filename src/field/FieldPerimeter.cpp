//
//  PerimeterFoodStartPosition.cpp
//  rhizopusApp
//
//  Created by Nuno on 09/05/2021.
//

#include "FieldPerimeter.h"

FieldPerimeter::FieldPerimeter(std::shared_ptr<IField> _field)
: field(_field)
{}

glm::vec2 FieldPerimeter::linearTo2D(int linearPos) const {
  auto size = field->getSize();
  if (linearPos < size.x) {
    return {linearPos,0};
  } else if (linearPos < size.x + size.y) {
    return {size.x, linearPos - size.x};
  } else if (linearPos < 2*size.x + size.y) {
    return {2*size.x + size.y  -linearPos, size.y};
  } else {
    return {0, 2*size.x + 2*size.y - linearPos};
  }
}

glm::vec2 FieldPerimeter::getMostAbundantPos(int areaSize) const {
  double highestValue = 0;
  int highestAreaFirstLinearPos = 0;
  int perimeter = 2*field->getSize().x + 2*field->getSize().y;
  
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
