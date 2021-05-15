//
//  PerimeterStartPos.h
//  rhizopusApp
//
//  Created by Nuno on 09/05/2021.
//

#ifndef PerimeterStartPos_h
#define PerimeterStartPos_h

#include "IField.h"
#include "IStartPos.h"

class PerimeterStartPos: public IStartPos {
private:
  std::shared_ptr<IField> field;
  int areaSize;

  glm::vec2 linearTo2D(int linearPos) const;

public:
  PerimeterStartPos(std::shared_ptr<IField> field, int areaSize);
  glm::vec2 get() const override;
};

#endif /* PerimeterStartPos */
