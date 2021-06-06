//
//  Hyphae.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "HyphaList.h"
#include "IHyphaCoordinatesGenerator.h"
#include "HyphaeStats.h"
#include "LifeDeathCounter.h"

class Hyphae {
private:
  shared_ptr<HyphaParams> hyphaParams;
  unique_ptr<IHyphaCoordinatesGenerator> generator;

  HyphaList elements;
  vector<glm::vec2> newPositions;
  LifeDeathCounter totalLifes;
  LifeDeathCounter lastUpdateLifes;
  double cachedDensity = 0;
  glm::vec2 cachedCenterOfMass = {0,0};
  int cacheValidity = 0;

  void addGenerated();
  int getMaxBirths() const;
  void updateCachedData();
  void add(const HyphaCoordinates coordinates, const double energy = 1.0f);
  void remove(Hypha& hypha);
  glm::vec2 getCenterOfMass() const;
  double getDensity();

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaMoved(HyphaMovedEventArgs &e);

public:
  Hyphae(shared_ptr<HyphaParams> hyphaParams, unique_ptr<IHyphaCoordinatesGenerator> generator);
  void update(IField &field);
  bool isAlive() const;

  vector<glm::vec2> getNewPositions() const;
  HyphaeStats getStats();
};

#endif /* Hyphae_h */
