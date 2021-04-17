//
//  Hyphae.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Hypha.h"

class Hyphae {
private:
  std::list<Hypha> elements;
  Field field;
  const HyphaParams hyphaParams;
  double initialEnergy = 0.5f;

  void add(const HyphaKynetics& kynetics);
  
  void onHyphaFork(HyphaForkEventArgs &e);

public:
  Hyphae(const HyphaParams& hyphaParams, const Field& field, const HyphaKynetics& kynetics);
  void update();
  std::vector<glm::vec2> getPositions() const;
};

#endif /* Hyphae_h */
