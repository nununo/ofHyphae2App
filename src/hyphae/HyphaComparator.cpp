//
//  HyphaComparator.cpp
//  rhizopusApp
//
//  Created by Nuno on 05/06/2021.
//

#include "HyphaComparator.h"

HyphaComparator::HyphaComparator(const glm::vec2 _reference)
: reference(_reference)
{}

bool HyphaComparator::operator ()(const Hypha & hypha1, const Hypha & hypha2) {
  auto d1 = glm::distance(reference, hypha1.getPosition());
  auto d2 = glm::distance(reference, hypha2.getPosition());
  return d1 < d2;
}

