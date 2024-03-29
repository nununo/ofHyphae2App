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
  const ofColor color;
  const ofBlendMode blendMode;
  const glm::vec2 offset;
  ofVboMesh mesh;

  void draw(std::vector<glm::vec3>) override;

public:
  HyphaePainter(const ofColor color, const glm::vec2 offset, const ofBlendMode blendMode);
};

#endif /* HyphaePainter_h */
