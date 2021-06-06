//
//  HyphaeStats.cpp
//  rhizopusApp
//
//  Created by Nuno on 03/06/2021.
//

#include "HyphaeStats.h"

HyphaeStats::HyphaeStats(
  const int _bornTotal,
  const int _deadTotal,
  const int _moved,
  const int _born,
  const int _died,
  const glm::vec2 _centerOfMass,
  const double _density)
: bornTotal(_bornTotal)
, deadTotal(_deadTotal)
, moved(_moved)
, born(_born)
, died(_died)
, centerOfMass(_centerOfMass)
, density(_density)
{
  growthPercentage = (born-died) / (double)(bornTotal-deadTotal-born+died) * 100;
}
