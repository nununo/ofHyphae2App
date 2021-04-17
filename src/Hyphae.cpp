//
//  Hyphae.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Hyphae.h"

Hyphae::Hyphae(const HyphaParams& _hyphaParams, const Field& _field)
: hyphaParams(_hyphaParams)
, field(_field)
{}

void Hyphae::add(const HyphaKynetics& kynetics) {
  elements.push_back(Hypha(hyphaParams, field, kynetics, initialEnergy));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.kynetics);
}
