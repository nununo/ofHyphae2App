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

std::vector<glm::vec2> Hyphae::getPositions() const {
  std::vector<glm::vec2> positions;
  for(auto& element : elements) {
    positions.push_back(element.getKynetics().getPos());
  }
  return positions;
}

void Hyphae::add(const HyphaKynetics& kynetics) {
  elements.push_back(Hypha(hyphaParams, field, kynetics, initialEnergy));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.kynetics);
}

void Hyphae::update() {
  for(auto& element : elements) {
    element.update();
  }
}

