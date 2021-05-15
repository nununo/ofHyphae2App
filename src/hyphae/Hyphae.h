//
//  Hyphae.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Hypha.h"
#include "IHyphaCoordinatesGenerator.h"

class Hyphae {
private:
  std::list<Hypha> elements;
  std::shared_ptr<IField> field;
  std::unique_ptr<IHyphaCoordinatesGenerator> generator;
  const HyphaParams hyphaParams;
  std::vector<glm::vec2> newPositions;
  
  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaMoved(HyphaMovedEventArgs &e);

public:
  Hyphae(const HyphaParams& hyphaParams, std::shared_ptr<IField> field, std::unique_ptr<IHyphaCoordinatesGenerator> generator);
  void update();
  void add(const HyphaCoordinates coordinates, const double energy = 1.0f);
  int count() const;
  std::vector<glm::vec2> getNewPositions() const;
  void clearNewPositions();
};

#endif /* Hyphae_h */
