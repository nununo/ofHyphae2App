//
//  SectorStartPos.cpp
//  rhizopusApp
//
//  Created by Nuno on 19/06/2021.
//

#include "SectorStartPos.h"

SectorStartPos::SectorStartPos(std::shared_ptr<IField> _field, int _sectorSize)
: field(_field)
, sectorSize(_sectorSize)
{}

glm::vec2 SectorStartPos::get() const {
  auto sectorWithMostFood = glm::vec3(0,0,0); // z = amount of food
  auto currentSector = glm::vec3(0,0,0);
  for(currentSector.x=0; currentSector.x<field->getSize().x; currentSector.x+=sectorSize) {
    for(currentSector.y=0; currentSector.y<field->getSize().y; currentSector.y+=sectorSize) {
      currentSector.z = 0; // Reset food
      auto cursor = glm::vec2(0,0);
      for(cursor.x=0; cursor.x<sectorSize; cursor.x++) {
        for(cursor.y=0; cursor.y<sectorSize; cursor.y++) {
          currentSector.z += field->getValue(currentSector + cursor);
        }
      }
      if (currentSector.z > sectorWithMostFood.z) {
        sectorWithMostFood = currentSector;
      }
    }
  }
  return sectorWithMostFood + glm::vec2(sectorSize/2, sectorSize/2);
}
