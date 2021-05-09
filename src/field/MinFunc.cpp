//
//  MinFunc.cpp
//  rhizopusApp
//
//  Created by Nuno on 08/05/2021.
//

#include "MinFunc.h"
#include <algorithm>

const double MinFunc::getValue(const std::vector<double> & values) const {
  return *std::min_element(std::begin(values), std::end(values));
}
