//
//  LifeDeathCounter.h
//  rhizopusApp
//
//  Created by Nuno on 05/06/2021.
//

#ifndef LifeDeathCounter_h
#define LifeDeathCounter_h

class LifeDeathCounter {
  int born = 0;
  int dead = 0;

public:
  void birth();
  void death();
  void reset();
  int getBirths() const;
  int getDeaths() const;
  int getDiff() const;
};

#endif /* LifeDeathCounter_h */
