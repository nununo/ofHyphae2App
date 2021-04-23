//
//  NoiseField.h
//  hyphae2App
//
//  Created by Nuno Godinho on 03/08/2020.
//

#ifndef NoiseField_h
#define NoiseField_h

#include "ofMain.h"
#include "FieldParams.h"
#include "IField.h"

class NoiseField : public IField {
private:
  const FieldParams params;
  const glm::vec2 size;
  vector< vector<double> > map;

  virtual glm::vec2 getSize() const;
  virtual double getValue(const glm::vec2 pos) const;
  virtual double consume(const glm::vec2 pos, const double amount);

  glm::vec2 normalize(const glm::vec2 pos) const;
  void populate();
  double calcFoodAtPosition(const int x, const int y) const;
  void setValue( glm::vec2 pos, double newValue);

public:
  NoiseField(const FieldParams& params, const glm::vec2 size);
};
#endif /* NoiseField_h */
