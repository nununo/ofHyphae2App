//
//  IFieldPainter.h
//  rhizopusApp
//
//  Created by Nuno on 16/05/2021.
//

#ifndef IFieldPainter_h
#define IFieldPainter_h

#include "IField.h"

class IFieldPainter {
public:
  virtual ~IFieldPainter() {}
  virtual void draw(const IField &field) = 0;
};

#endif /* IFieldPainter_h */
