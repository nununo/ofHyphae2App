//
//  SettingsFile.cpp
//  rhizopusApp
//
//  Created by Nuno on 14/04/2021.
//

#include "SettingsFile.h"

int SettingsFile::pushTags(const string& xmlPath) {
  int pos;
  int levels = 0;
  string tag = xmlPath;
  do {
    pos = tag.find(":");
    string tagToFind((pos > 0) ? tag.substr(0,pos) :tag);
    f.pushTag(tagToFind);
    levels++;
    if (pos>0) {
      tag = tag.substr(pos+1);
    }
  } while (pos>0);
  return levels;
}

void SettingsFile::popTags(int levels) {
  for(int i=0;i<levels;i++) {
    f.popTag();
  }
}

glm::vec2 SettingsFile::getRange(const string& xmlPath, const double defaultValue) const {
  return glm::vec2(f.getValue(xmlPath + ":min", defaultValue),
                   f.getValue(xmlPath + ":max", defaultValue));
}

vector<double> SettingsFile::getSet(const string& xmlPath) {
  vector<double> list;
  double value;

  int levels = pushTags(xmlPath);
  int numElements = f.getNumTags("v");
  for(int i=0; i<numElements; i++){
    value = f.getValue("v", 0.0f, i);
    list.push_back(value);
  }
  
  popTags(levels);
  return list;
}

ofColor SettingsFile::getColor(const string& xmlPath, const ofColor defaultValue) const {
  return ofColor(f.getValue(xmlPath + ":r", defaultValue.r),
                 f.getValue(xmlPath + ":g", defaultValue.g),
                 f.getValue(xmlPath + ":b", defaultValue.b),
                 f.getValue(xmlPath + ":a", defaultValue.a));
}
