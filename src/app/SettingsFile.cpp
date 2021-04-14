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

ofVec2f SettingsFile::getRange(const string& xmlPath, const float defaultValue) const {
  return ofVec2f(f.getValue(xmlPath + ":min", defaultValue),
                 f.getValue(xmlPath + ":max", defaultValue));
}

vector<float> SettingsFile::getSet(const string& xmlPath) {
  vector<float> list;
  float value;

  int levels = pushTags(xmlPath);
  int numElements = f.getNumTags("v");
  for(int i=0; i<numElements; i++){
    value = f.getValue("v", 0.0f, i);
    list.push_back(value);
  }
  
  popTags(levels);
  return list;
}

ofColor SettingsFile::getColor(const string& xmlPath) const {
  return ofColor(f.getValue(xmlPath + ":r", 0),
                 f.getValue(xmlPath + ":g", 0),
                 f.getValue(xmlPath + ":b", 0),
                 f.getValue(xmlPath + ":a", 255));
}
