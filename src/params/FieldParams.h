//
//  FieldParams.h
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#ifndef FieldParams_h
#define FieldParams_h

#include "FieldSettings.h"

class FieldParams {
public:
  const double zeroThreshold;
  
  FieldParams(const FieldSettings& fieldSettings);
};

#endif /* FieldParams_h */
