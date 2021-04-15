//
//  SettingsFile.h
//  rhizopusApp
//
//  Created by Nuno on 14/04/2021.
//

#ifndef SettingsFile_h
#define SettingsFile_h

#include "ofxXmlSettings.h"

class SettingsFile {
private:
  ofxXmlSettings f;

  int pushTags(const string& xmlPath);
  void popTags(int levels);

public:
  SettingsFile(const string& xmlFilename) {f.loadFile(xmlFilename);}
  glm::vec2 getRange(const string& xmlPath, const float defaultValue=0.0f) const;
  ofColor getColor(const string& xmlPath, const ofColor defaultValue=ofColor::red) const;
  vector<float> getSet(const string& xmlPath);
  int getValue(const string& tag, int defaultValue, int which = 0) const {return f.getValue(tag, defaultValue, which);}
  double getValue(const string& tag, double defaultValue, int which = 0) const {return f.getValue(tag, defaultValue, which);}
  string getValue(const string& tag, const string& defaultValue, int which = 0) const {return f.getValue(tag, defaultValue, which);}
};

#endif /* SettingsFile_h */
