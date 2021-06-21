//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"
#include "HyphaComparator.h"

Hyphae::Hyphae(shared_ptr<const HyphaParams> _hyphaParams,
               unique_ptr<IHyphaCoordinatesGenerator> _generator)
: hyphaParams(_hyphaParams)
, generator(std::move(_generator))
, birthControl(make_unique<HyphaeBirthControl>(_hyphaParams->maxGrowthPercentage, 80.0f)) // TODO
{}

void Hyphae::add(const HyphaCoordinates coordinates, const double energy, const HyphaStatus status) {
  elements.push_back(Hypha(hyphaParams, coordinates, energy, status));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
  ofAddListener(elements.back().movedEvent, this, &Hyphae::onHyphaMoved);
  birthControl->birth();
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.coordinates, e.energy, e.status);
}

void Hyphae::onHyphaMoved(HyphaMovedEventArgs &e) {
  newPositions.push_back(e.pos);
}

void Hyphae::addGenerated() {
  auto v = generator->get();
  for(auto p: v) {
    add(p, 1, HyphaStatus::BeforeInside);
  }
}

void Hyphae::update(IField &field) {
  updateCachedData();
  birthControl->reset(getDensity());
  newPositions.clear();
  addGenerated();
  for(auto itr = elements.begin(); itr != elements.end(); ++itr) {
    if (itr->isAlive()) {
      itr->update(field, birthControl->allowFork());
    } else {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      ofRemoveListener(itr->movedEvent, this, &Hyphae::onHyphaMoved);
      itr = elements.erase(itr);
      birthControl->death();
    }
  }
}

vector<glm::vec2> Hyphae::getNewPositions() const {
  return newPositions;
}

HyphaeStats Hyphae::getStats() {
  return HyphaeStats(
                     elements.size(),
                     getNewPositions().size(),
                     birthControl->getLatestBirths(),
                     birthControl->getLatestDeaths(),
                     birthControl->getFertilityRatio(),
                     getCenterOfMass(),
                     getDensity());
}

bool Hyphae::isAlive() const {
  return elements.size() > 0;
}

void Hyphae::updateCachedData() {
  /*
   Sort elements based on their center of mass so that we can then find their density by
   picking the distance to center of mass of 80% of its elements.
   */
  if (--cacheValidity<=0) {
    cachedCenterOfMass = elements.getCenterOfMass();
    cachedDensity = elements.size()<100? 0 : elements.getDensity(80); // TODO
    cacheValidity = 10; // TODO
  }
}
