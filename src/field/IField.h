//
//  IField.h
//  rhizopusApp
//
//  Created by Nuno on 23/04/2021.
//

#ifndef IField_h
#define IField_h

#include "ofMain.h"

class IField {
public:
  virtual ~IField() {};
  virtual glm::vec2 getSize() const = 0;
  virtual double getValue(const glm::vec2 pos) const = 0;
  virtual double consume(const glm::vec2 pos, const double amount) = 0;
  virtual bool isInside(const glm::vec2 pos) const = 0;
};

#endif /* IField_h */
