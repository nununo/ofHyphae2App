//
//  Params.cpp
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#include "Params.h"

Params::Params(const Settings &settings)
: hypha(std::make_shared<HyphaParams>(*settings.hypha))
, field(std::make_shared<FieldParams>(*settings.field))
{}
