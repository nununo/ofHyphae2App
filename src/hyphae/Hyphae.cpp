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
, birthControl(make_unique<HyphaeBirthControl>(_hyphaParams->maxGrowthPercentage, _hyphaParams->fertilityRatio, _hyphaParams->maxElements))
, firstFrameNum(ofGetFrameNum())
{}

void Hyphae::add(const HyphaCoordinates coordinates, const double energy, const HyphaStatus status) {
  elements.push_back(Hypha(hyphaParams, coordinates, energy, status));
  birthControl->birth();
}

void Hyphae::addGenerated() {
  auto v = generator->get();
  for(auto p: v) {
    add(p, 1, HyphaStatus::BeforeInside);
  }
}

void Hyphae::update(const IField &field) {
  birthControl->newFrame();
  newPositions.clear();
  if (dead) {
    return;
  }
  addGenerated();
  for(auto itr = elements.begin(); itr != elements.end(); ++itr) {
    if (itr->isAlive()) {
      hyphaUpdate(field, *itr);
      hyphaFork(*itr);
    } else {
      if (itr->getPosition().x >= field.getSize().x) {
        dead = true;
      }
      itr = elements.erase(itr);
      birthControl->death();
    }
  }
  if (elements.size() == 0) {
    dead = true;
  }
}

void Hyphae::hyphaUpdate(const IField &field, Hypha &hypha) {
  if (hypha.update(field)) {
    auto pos2 = hypha.getPosition();
    newPositions.push_back(glm::vec3(pos2.x, pos2.y, 0));
  }
}

void Hyphae::hyphaFork(Hypha &hypha) {
  if (birthControl->allowFork()) {
    auto forkData = hypha.fork();
    if (forkData.energy > 0) {
      add(forkData.coordinates, forkData.energy, forkData.status);
    }
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
    birthControl->getCurrentFertilityRatio(),
    getLifetime(),
    isAlive());
}

bool Hyphae::isAlive() const {
  return !dead;
}

int Hyphae::getLifetime() const {
  return (ofGetFrameNum() - firstFrameNum) / ofGetFrameRate();
}
