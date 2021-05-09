//
//  MaxFunc.h
//  rhizopusApp
//
//  Created by Nuno on 08/05/2021.
//

#ifndef MaxFunc_h
#define MaxFunc_h

#include <vector>
#include "IMultiFunc.h"

class MaxFunc: public IMultiFunc {
private:
  const double getValue(const std::vector<double> & values) const override;
};
#endif /* MaxFunc_h */
