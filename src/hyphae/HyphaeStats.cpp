//
//  HyphaeStats.cpp
//  rhizopusApp
//
//  Created by Nuno on 03/06/2021.
//

#include "HyphaeStats.h"

HyphaeStats::HyphaeStats(
  const int _alive,
  const int _moved,
  const int _born,
  const int _died,
  const double _fertilityRatio)
: alive(_alive)
, moved(_moved)
, born(_born)
, died(_died)
, fertilityRatio(_fertilityRatio)
{}
