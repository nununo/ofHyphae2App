//
//  FieldParams.cpp
//  rhizopusApp
//
//  Created by Nuno on 16/04/2021.
//

#include "FieldParams.h"
#include "Tools.h"

FieldParams::FieldParams(const FieldSettings& fieldSettings)
: frequency(Tools::randomInRange(fieldSettings.frequency))
, amplification(Tools::randomInRange(fieldSettings.amplification))
{}
