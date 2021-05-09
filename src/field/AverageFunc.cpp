//
//  AverageFunc.cpp
//  rhizopusApp
//
//  Created by Nuno on 08/05/2021.
//

#include "AverageFunc.h"
#include <numeric>

const double AverageFunc::getValue(const std::vector<double> & values) const {
  double total = 0;
  if (values.size() > 0) {
    total = std::accumulate( values.begin(), values.end(), 0.0f) / values.size();
  }
  return total;
}
