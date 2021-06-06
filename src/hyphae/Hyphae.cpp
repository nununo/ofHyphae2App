//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"
#include "HyphaComparator.h"

Hyphae::Hyphae(std::shared_ptr<HyphaParams> _hyphaParams,
               std::unique_ptr<IHyphaCoordinatesGenerator> _generator)
: hyphaParams(_hyphaParams)
, generator(std::move(_generator))
{}

void Hyphae::add(const HyphaCoordinates coordinates, const double energy) {
  elements.push_back(Hypha(hyphaParams, coordinates, energy));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
  ofAddListener(elements.back().movedEvent, this, &Hyphae::onHyphaMoved);
  totalLifes.birth();
  lastUpdateLifes.birth();
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.coordinates, e.energy);
}

void Hyphae::onHyphaMoved(HyphaMovedEventArgs &e) {
  newPositions.push_back(e.pos);
}

void Hyphae::addGenerated() {
  auto v = generator->get();
  for(auto p: v) {
    add(p);
  }
}

bool Hyphae::birthControl() {
  auto maxBirths = getMaxBirths();
  return lastUpdateLifes.getDiff()<maxBirths && getDensity() < 80.0f; // TODO
}

void Hyphae::update(IField &field) {
  updateCachedData();
  lastUpdateLifes.reset();
  newPositions.clear();
  addGenerated();
  for(auto itr = elements.begin(); itr != elements.end(); ++itr) {
    if (itr->isAlive()) {
      itr->update(field, birthControl());
    } else {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      ofRemoveListener(itr->movedEvent, this, &Hyphae::onHyphaMoved);
      itr = elements.erase(itr);
      totalLifes.death();
      lastUpdateLifes.death();
    }
  }
}

vector<glm::vec2> Hyphae::getNewPositions() const {
  return newPositions;
}

HyphaeStats Hyphae::getStats() {
  return HyphaeStats(
                     totalLifes.getBirths(),
                     totalLifes.getDeaths(),
                     totalLifes.getDiff(),
                     lastUpdateLifes.getBirths(),
                     lastUpdateLifes.getDeaths(),
                     getCenterOfMass(),
                     getDensity());
}

int Hyphae::getMaxBirths() const {
  auto maxBirths = totalLifes.getDiff() * hyphaParams->maxGrowthPercentage / 100.0f;
  return maxBirths>10? maxBirths : 10; // TODO
}

bool Hyphae::isAlive() const {
  return elements.size() > 0;
}

void Hyphae::updateCachedData() {
  if (--cacheValidity<=0) {
    cachedCenterOfMass = elements.getCenterOfMass();
    cachedDensity = elements.size()<100? 0 : elements.getDensity(80); // TODO
    cacheValidity = 10; // TODO
  }
}

glm::vec2 Hyphae::getCenterOfMass() const {
  return cachedCenterOfMass;
}

/*
 Sort elements based on their center of mass so that we can then find their density by
 picking the distance to center of mass of 80% of its elements.
 */
double Hyphae::getDensity() {
  return cachedDensity;
}
