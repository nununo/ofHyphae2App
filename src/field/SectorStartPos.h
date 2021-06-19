//
//  SectorStartPos.h
//  rhizopusApp
//
//  Created by Nuno on 19/06/2021.
//

#ifndef SectorStartPos_h
#define SectorStartPos_h

#include "IStartPos.h"
#include "IField.h"

class SectorStartPos: public IStartPos {
private:
  std::shared_ptr<IField> field;
  int sectorSize;

public:
  SectorStartPos(std::shared_ptr<IField> field, int sectorSize);
  glm::vec2 get() const override;
};

#endif /* SectorStartPos_h */
