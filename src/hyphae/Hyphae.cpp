//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"

Hyphae::Hyphae(const HyphaParams& _hyphaParams, IField *_field, const HyphaCoordinates coordinates)
: hyphaParams(_hyphaParams)
, field(_field)
{
  add(coordinates, 1.0f);
}

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
