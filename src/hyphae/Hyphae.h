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

class Hyphae {
private:
  shared_ptr<const HyphaParams> hyphaParams;
  unique_ptr<IHyphaCoordinatesGenerator> generator;
  const int firstFrameNum;

  list<Hypha> elements;
  vector<glm::vec3> newPositions;
  unique_ptr<HyphaeBirthControl> birthControl;
  bool dead = false;
  int finishLines = 0;

  void addGenerated();
  void add(const HyphaCoordinates coordinates, const double energy);
  void hyphaUpdate(const IField &field, Hypha &hypha);
  void hyphaFork(Hypha &hypha);
  void hyphaFinishLine(const Hypha &hypha, const IField &field);
  
public:
  Hyphae(shared_ptr<const HyphaParams> hyphaParams, unique_ptr<IHyphaCoordinatesGenerator> generator);
  void update(const IField &field);
  bool isAlive() const;
  int getLifetime() const;
  vector<glm::vec3> getNewPositions() const;
  HyphaeStats getStats();
};

#endif /* Hyphae_h */
