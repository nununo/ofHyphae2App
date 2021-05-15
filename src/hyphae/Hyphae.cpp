//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"

Hyphae::Hyphae(const HyphaParams& _hyphaParams, std::shared_ptr<IField> _field, std::unique_ptr<IHyphaCoordinatesGenerator> _generator)
: hyphaParams(_hyphaParams)
, field(_field)
, generator(std::move(_generator))
{}

std::vector<glm::vec2> Hyphae::getNewPositions() const {
  return newPositions;
}

int Hyphae::count() const {
  return elements.size();
}

void Hyphae::clearNewPositions() {
  newPositions.clear();
}

void Hyphae::add(const HyphaCoordinates coordinates, const double energy) {
  elements.push_back(Hypha(hyphaParams, field, coordinates, energy));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
  ofAddListener(elements.back().movedEvent, this, &Hyphae::onHyphaMoved);
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.coordinates, e.energy);
}

void Hyphae::onHyphaMoved(HyphaMovedEventArgs &e) {
  newPositions.push_back(e.pos);
}

void Hyphae::update() {
  auto v = generator->get();
  for(auto p: v) {
    add(p);
  }
  for(auto itr = elements.begin(); itr != elements.end(); ++itr) {
    if (itr->isAlive()) {
      itr->update();
    } else {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      ofRemoveListener(itr->movedEvent, this, &Hyphae::onHyphaMoved);
      itr = elements.erase(itr);
    }
  }
}
