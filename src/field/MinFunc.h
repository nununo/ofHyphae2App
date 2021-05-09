//
//  MinFunc.h
//  rhizopusApp
//
//  Created by Nuno on 08/05/2021.
//

#ifndef MinFunc_h
#define MinFunc_h

#include <vector>
#include "IMultiFunc.h"

class MinFunc: public IMultiFunc {
private:
  const double getValue(const std::vector<double> & values) const override;
};
#endif /* MinFunc_h */
