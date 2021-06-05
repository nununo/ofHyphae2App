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
#include "HyphaeStats.h"
#include "LifeDeathCounter.h"

class Hyphae {
private:
  shared_ptr<HyphaParams> hyphaParams;
  list<Hypha> elements;
  unique_ptr<IHyphaCoordinatesGenerator> generator;
  vector<glm::vec2> newPositions;
  LifeDeathCounter totalLifes;
  LifeDeathCounter lastUpdateLifes;

  void addGenerated();

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaMoved(HyphaMovedEventArgs &e);

public:
  Hyphae(shared_ptr<HyphaParams> hyphaParams, unique_ptr<IHyphaCoordinatesGenerator> generator);
  void update(IField &field);
  void add(const HyphaCoordinates coordinates, const double energy = 1.0f);
  int count() const;
  
  vector<glm::vec2> getNewPositions() const;
  HyphaeStats getStats() const;
};

#endif /* Hyphae_h */
