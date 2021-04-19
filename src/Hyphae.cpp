//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"

Hyphae::Hyphae(const HyphaParams& _hyphaParams, const Field& _field, const HyphaKynetics& kynetics)
: hyphaParams(_hyphaParams)
, field(_field)
{
  add(kynetics);
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

void Hyphae::add(const HyphaKynetics& kynetics) {
  elements.push_back(Hypha(hyphaParams, field, kynetics, initialEnergy));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
  ofAddListener(elements.back().movedEvent, this, &Hyphae::onHyphaMoved);
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.kynetics);
}

void Hyphae::onHyphaMoved(HyphaForkEventArgs &e) {
  newPositions.push_back(e.kynetics.getPos());
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
