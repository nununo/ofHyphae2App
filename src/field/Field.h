//
//  Field.hpp
//  hyphae2App
//
//  Created by Nuno Godinho on 03/08/2020.
//

#ifndef Field_h
#define Field_h

#include "ofMain.h"

class Field {
private:
  vector< vector<float> > map;

  glm::vec2 normalize(const glm::vec2 pos) const;
  void populate();
  float calcFoodAtPosition(const int x, const int y) const;
  void setValue( glm::vec2 pos, float newValue) {map[(int)pos.y][(int)pos.x] = newValue;}

public:
  Field(const int width, const int height);
  int getWidth() const {return map[0].size();}
  int getHeight() const {return map.size();}
  float getValue(const glm::vec2 pos) const {return map[(int)pos.y][(int)pos.x];}
  float consume(const glm::vec2 pos, const float diff);
};
#endif /* Field_h */
