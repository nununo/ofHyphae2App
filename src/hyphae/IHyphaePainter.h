//
//  IHyphaePainter.h
//  rhizopusApp
//
//  Created by Nuno on 16/05/2021.
//

#ifndef IHyphaePainter_h
#define IHyphaePainter_h

#include "ofMain.h"

class IHyphaePainter {
public:
  virtual ~IHyphaePainter() {}
  virtual void draw(std::vector<glm::vec3>) = 0;
};

#endif /* IHyphaePainter_h */
