//
//  Hyphae.h
//  rhizopusApp
//
//  Created by Nuno on 17/04/2021.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Hypha.h"
#include "IHyphaCoordinatesGenerator.h"
#include "IHyphaePainter.h"
#include "IDrawable.h"

class Hyphae: public IDrawable {
private:
  const HyphaParams hyphaParams;
  std::list<Hypha> elements;
  std::shared_ptr<IField> field;
  std::unique_ptr<IHyphaCoordinatesGenerator> generator;
  std::unique_ptr<IHyphaePainter> painter;
  std::vector<glm::vec2> newPositions;

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaMoved(HyphaMovedEventArgs &e);

public:
  Hyphae(const HyphaParams& hyphaParams,
         std::shared_ptr<IField> field,
         std::unique_ptr<IHyphaCoordinatesGenerator> generator,
         std::unique_ptr<IHyphaePainter> painter);
  void add(const HyphaCoordinates coordinates, const double energy = 1.0f);
  int count() const;

  // IDrawable
  void update() override;
  void draw() override;
};

#endif /* Hyphae_h */
