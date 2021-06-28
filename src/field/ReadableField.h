//
//  ReadableField.h
//  rhizopusApp
//
//  Created by Nuno on 28/06/2021.
//

#ifndef ReadableField_h
#define ReadableField_h

#include "IField.h"

class ReadableField: public virtual IField {
private:
  const glm::vec2 size;
  
  vector< vector<double> > map;
  int rightTolerance = 0;
  
  bool isInside(const glm::vec2 pos) const override;
  
protected:
  glm::vec2 getSize() const override;
  double getValue(const glm::vec2 pos) const override;
  void setValue(glm::vec2 pos, double newValue);
  void setRightTolerance(int rightTolerance);

public:
  ReadableField(const glm::vec2 size);
};

#endif /* ReadableField_h */
