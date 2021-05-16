//
//  HyphaePainter.h
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

#ifndef HyphaePainter_h
#define HyphaePainter_h

#include "IHyphaePainter.h"

class HyphaePainter: public IHyphaePainter {
private:
  ofColor color;

  void draw(std::vector<glm::vec2>) override;

public:
  HyphaePainter(const ofColor color);
};

#endif /* HyphaePainter_h */
