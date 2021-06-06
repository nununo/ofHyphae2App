//
//  HyphaComparator.h
//  rhizopusApp
//
//  Created by Nuno on 05/06/2021.
//

#ifndef HyphaComparator_h
#define HyphaComparator_h

#include "Hypha.h"

class HyphaComparator {
  glm::vec2 reference;

public:
  HyphaComparator(const glm::vec2 reference);
  bool operator ()(const Hypha & hypha1, const Hypha & Hypha2);
};

#endif /* HyphaComparator_h */
