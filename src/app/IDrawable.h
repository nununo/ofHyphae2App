//
//  IDrawable.h
//  rhizopusApp
//
//  Created by Nuno on 16/05/2021.
//

#ifndef IDrawable_h
#define IDrawable_h

class IDrawable {
public:
  virtual ~IDrawable() {}
  virtual void update() {}
  virtual void draw() = 0;
};

#endif /* IDrawable_h */
