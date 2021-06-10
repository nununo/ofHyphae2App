//
//  AbundanceFieldGenerator.h
//  rhizopusApp
//
//  Created by Nuno on 10/06/2021.
//

#ifndef AbundanceFieldGenerator_h
#define AbundanceFieldGenerator_h

#include "IFieldGenerator.h"

class AbundanceFieldGenerator: public IFieldGenerator {
private:
  double getValue(const glm::vec2 normalizedPos) const override;
};

#endif /* AbundanceFieldGenerator_h */
