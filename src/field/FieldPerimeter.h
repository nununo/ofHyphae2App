//
//  FieldPerimeter.h
//  rhizopusApp
//
//  Created by Nuno on 09/05/2021.
//

#ifndef FieldPerimeter_h
#define FieldPerimeter_h

#include "IField.h"

class FieldPerimeter {
private:
  std::shared_ptr<IField> field;

  glm::vec2 linearTo2D(int linearPos) const;
  
public:
  FieldPerimeter(std::shared_ptr<IField> field);
  glm::vec2 getMostAbundantPos(int areaSize) const;
};

#endif /* FieldPerimeter_h */
