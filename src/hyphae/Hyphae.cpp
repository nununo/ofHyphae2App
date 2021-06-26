//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"

Hyphae::Hyphae(shared_ptr<const HyphaParams> _hyphaParams,
               unique_ptr<IHyphaCoordinatesGenerator> _generator)
: hyphaParams(_hyphaParams)
, generator(std::move(_generator))
, birthControl(make_unique<HyphaeBirthControl>(_hyphaParams->maxGrowthPercentage, _hyphaParams->fertilityRatio))
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
  if (dead) {
    return;
  }
  addGenerated();
  for(auto itr = elements.begin(); itr != elements.end(); ++itr) {
    if (itr->isAlive()) {
      if (itr->update(field, birthControl->allowFork())) {
        auto pos2 = itr->getPosition();
        newPositions.push_back(glm::vec3(pos2.x, pos2.y, 0));
      }
    } else {
      if (itr->getPosition().x >= field.getSize().x) {
        dead = true;
      }
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      itr = elements.erase(itr);
      birthControl->death();
    }
  }
  if (elements.size() == 0) {
    dead = true;
  }
}

vector<glm::vec3> Hyphae::getNewPositions() const {
  return newPositions;
}

HyphaeStats Hyphae::getStats() {
  return HyphaeStats(
                     elements.size(),
                     getNewPositions().size(),
                     birthControl->getLatestBirths(),
                     birthControl->getLatestDeaths(),
                     birthControl->getCurrentFertilityRatio());
}

bool Hyphae::isAlive() const {
  return !dead;
}
