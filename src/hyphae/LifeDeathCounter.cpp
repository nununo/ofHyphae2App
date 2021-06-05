//
//  LifeDeathCounter.cpp
//  rhizopusApp
//
//  Created by Nuno on 05/06/2021.
//

#include "LifeDeathCounter.h"

void LifeDeathCounter::birth() {born++;}
void LifeDeathCounter::death() {dead++;}
void LifeDeathCounter::reset() {born=0; dead=0;};
int LifeDeathCounter::getBirths() const {return born;}
int LifeDeathCounter::getDeaths() const {return dead;}
int LifeDeathCounter::getDiff() const {return born - dead;}
