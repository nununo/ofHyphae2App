//
//  MaxFunc.cpp
//  rhizopusApp
//
//  Created by Nuno on 08/05/2021.
//

#include "MaxFunc.h"
#include <algorithm>

const double MaxFunc::getValue(const std::vector<double> & values) const {
  return *std::max_element(std::begin(values), std::end(values));
}
