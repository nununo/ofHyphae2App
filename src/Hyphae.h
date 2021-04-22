//
//  Hyphae.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Hypha.h"
#include "HyphaCoordinates.h"

class Hyphae {
private:
  std::list<Hypha> elements;
  Field * const field;
  const HyphaParams hyphaParams;
  double initialEnergy = 1.0f;
  std::vector<glm::vec2> newPositions;

  void add(const HyphaCoordinates coordinates);
  
  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaMoved(HyphaMovedEventArgs &e);

public:
  Hyphae(const HyphaParams& hyphaParams, Field *field, const HyphaCoordinates coordinates);
  void update();
  int count() const;
  std::vector<glm::vec2> getNewPositions() const;
  void clearNewPositions();
};

#endif /* Hyphae_h */
