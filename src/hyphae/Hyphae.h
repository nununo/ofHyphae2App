//
//  Hyphae.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "IHyphaCoordinatesGenerator.h"
#include "HyphaeStats.h"
#include "HyphaeBirthControl.h"
#include "HyphaParams.h"
#include "Hypha.h"
#include "HyphaStatus.h"

class Hyphae {
private:
  shared_ptr<const HyphaParams> hyphaParams;
  unique_ptr<IHyphaCoordinatesGenerator> generator;

  list<Hypha> elements;
  vector<glm::vec2> newPositions;
  unique_ptr<HyphaeBirthControl> birthControl;

  void addGenerated();
  void add(const HyphaCoordinates coordinates, const double energy, const HyphaStatus status);

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaMoved(HyphaMovedEventArgs &e);

public:
  Hyphae(shared_ptr<const HyphaParams> hyphaParams, unique_ptr<IHyphaCoordinatesGenerator> generator);
  void update(IField &field);
  bool isAlive() const;

  vector<glm::vec2> getNewPositions() const;
  HyphaeStats getStats();
};

#endif /* Hyphae_h */
