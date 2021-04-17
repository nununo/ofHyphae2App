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
  void setValue( glm::vec2 pos, double newValue);

public:
  Field(const FieldParams& params, const int width, const int height);
  int getWidth() const;
  int getHeight() const;
  double getValue(const glm::vec2 pos) const;
  double consume(const glm::vec2 pos, const double amount);
};
#endif /* Field_h */
