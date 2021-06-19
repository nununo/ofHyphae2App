//
//  IStartPos.h
//  rhizopusApp
//
//  Created by Nuno on 15/05/2021.
//

#ifndef IStartPos_h
#define IStartPos_h

#include "ofMain.h"

class IStartPos {
public:
  virtual ~IStartPos() {}
  virtual glm::vec2 get() const = 0;
};

#endif /* IStartPos_h */
