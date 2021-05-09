//
//  AverageFunc.h
//  rhizopusApp
//
//  Created by Nuno on 08/05/2021.
//

#ifndef AverageFunc_h
#define AverageFunc_h

#include <vector>
#include "IMultiFunc.h"

class AverageFunc: public IMultiFunc {
private:
  const double getValue(const std::vector<double> & values) const override;
};
#endif /* AverageFunc_h */
