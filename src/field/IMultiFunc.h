//
//  IMultiFunc.h
//  rhizopusApp
//
//  Created by Nuno on 08/05/2021.
//

#ifndef IMultiFunc_h
#define IMultiFunc_h

#include <vector>

class IMultiFunc {
public:
  virtual ~IMultiFunc() {};
  virtual const double getValue(const std::vector<double> & values) const = 0;
};

#endif /* IMultiFunc_h */
