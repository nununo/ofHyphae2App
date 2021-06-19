//
//  SettingsFile.cpp
//  rhizopusApp
//
//  Created by Nuno on 14/04/2021.
//

#include "SettingsFile.h"

int SettingsFile::pushTags(const string& xmlPath) {
  unsigned long pos;
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

Range SettingsFile::getRange(const string& xmlPath) const {
  return {
    .min = f.getValue(xmlPath + ":min", 0.0f),
    .max = f.getValue(xmlPath + ":max", 0.0f)
  };
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

ofColor SettingsFile::getColor(const string& xmlPath) const {
  return ofColor(f.getValue(xmlPath + ":r", ofColor::black.r),
                 f.getValue(xmlPath + ":g", ofColor::black.g),
                 f.getValue(xmlPath + ":b", ofColor::black.b),
                 f.getValue(xmlPath + ":a", ofColor::black.a));
}
