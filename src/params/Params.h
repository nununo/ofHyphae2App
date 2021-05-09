//
//  Params.h
//  rhizopusApp
//
//  Created by Nuno on 15/04/2021.
//

#ifndef Params_h
#define Params_h

#include "Settings.h"
#include "HyphaParams.h"
#include "FieldParams.h"

class Params {
public:
  const HyphaParams hypha;
  const FieldParams field;
  
  Params(const Settings &settings);
};
#endif /* Params_h */
