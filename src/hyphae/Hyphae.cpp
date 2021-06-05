//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"

Hyphae::Hyphae(std::shared_ptr<HyphaParams> _hyphaParams,
               std::unique_ptr<IHyphaCoordinatesGenerator> _generator)
: hyphaParams(_hyphaParams)
, generator(std::move(_generator))
{}

int Hyphae::count() const {
  return elements.size();
}

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

void Hyphae::update(IField &field) {
  auto maxBirths = getMaxBirths();
  lastUpdateLifes.reset();
  newPositions.clear();
  addGenerated();
  for(auto itr = elements.begin(); itr != elements.end(); ++itr) {
    if (itr->isAlive()) {
      itr->update(field, lastUpdateLifes.getDiff()<maxBirths);
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

HyphaeStats Hyphae::getStats() const {
  return HyphaeStats(totalLifes.getBirths(), totalLifes.getDeaths(), totalLifes.getDiff(), lastUpdateLifes.getBirths(), lastUpdateLifes.getDeaths());
}

int Hyphae::getMaxBirths() const {
  auto maxBirths = totalLifes.getDiff() * hyphaParams->maxGrowthPercentage / 100.0f;
  return maxBirths>10? maxBirths : 10;
}
