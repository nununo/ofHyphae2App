//
//  Field.hpp
//  hyphae2App
//
//  Created by Nuno Godinho on 03/08/2020.
//

#ifndef Field_h
#define Field_h

#include "ofMain.h"
#include "FieldParams.h"

class Field {
private:
  const FieldParams params;
  vector< vector<double> > map;

  glm::vec2 normalize(const glm::vec2 pos) const;
  void populate();
  double calcFoodAtPosition(const int x, const int y) const;
  void setValue( glm::vec2 pos, double newValue) {map[(int)pos.y][(int)pos.x] = (newValue>0? newValue : 0);}

public:
  Field(const FieldParams& params, const int width, const int height);
  int getWidth() const {return map[0].size();}
  int getHeight() const {return map.size();}
  double getValue(const glm::vec2 pos) const {return map[(int)pos.y][(int)pos.x];}
  double consume(const glm::vec2 pos, const double amount);
};
#endif /* Field_h */
