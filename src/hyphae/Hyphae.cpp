//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"
#include "HyphaComparator.h"

Hyphae::Hyphae(shared_ptr<const HyphaParams> _hyphaParams,
               unique_ptr<IHyphaCoordinatesGenerator> _generator,
               shared_ptr<IOccupancy> occupancy)
: hyphaParams(_hyphaParams)
, generator(std::move(_generator))
, birthControl(make_unique<HyphaeBirthControl>(_hyphaParams->maxGrowthPercentage, occupancy))
{}

void Hyphae::add(const HyphaCoordinates coordinates, const double energy, const HyphaStatus status) {
  elements.push_back(Hypha(hyphaParams, coordinates, energy, status));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
  birthControl->birth();
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.coordinates, e.energy, e.status);
}

void Hyphae::addGenerated() {
  auto v = generator->get();
  for(auto p: v) {
    add(p, 1, HyphaStatus::BeforeInside);
  }
}

void Hyphae::update(IField &field) {
  birthControl->reset();
  newPositions.clear();
  addGenerated();
  for(auto itr = elements.begin(); itr != elements.end(); ++itr) {
    if (itr->isAlive()) {
      if (itr->update(field, birthControl->allowFork(itr->getPosition()))) {
        newPositions.push_back(itr->getPosition());
      }
    } else {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
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
                     birthControl->getFertilityRatio());
}

bool Hyphae::isAlive() const {
  return elements.size() > 0;
}
