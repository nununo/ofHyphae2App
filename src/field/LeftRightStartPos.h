//
//  LeftRightStartPos.h
//  rhizopusApp
//
//  Created by Nuno on 19/06/2021.
//

#ifndef LeftRightStartPos_h
#define LeftRightStartPos_h

#include "IStartPos.h"
#include "IField.h"

class LeftRightStartPos: public IStartPos {
private:
  std::shared_ptr<IField> field;
  const int probeSize;

public:
  LeftRightStartPos(std::shared_ptr<IField> field, const int probeSize);
  glm::vec2 get() const override;
};

#endif /* LeftRightStartPos_h */
