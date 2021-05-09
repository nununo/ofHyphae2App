//
//  WritableField.h
//  rhizopusApp
//
//  Created by Nuno on 24/04/2021.
//

#ifndef WritableField_h
#define WritableField_h

#include "IFieldGenerator.h"
#include "IField.h"

class WritableField: public IField {
private:
  const glm::vec2 size;
  vector< vector<double> > map;

  virtual glm::vec2 getSize() const;
  virtual double getValue(const glm::vec2 pos) const;
  virtual double consume(const glm::vec2 pos, const double amount);

  glm::vec2 normalize(const glm::vec2 pos) const;
  void setValue( glm::vec2 pos, double newValue);

public:
  WritableField(const glm::vec2 size);
  void write(const std::shared_ptr<IFieldGenerator> generator);
};
#endif /* WritableField_h */
