//
//  Fader.cpp
//  rhizopusApp
//
//  Created by Nuno on 27/06/2021.
//

#include "FadePainter.h"

FadePainter::FadePainter(const int framesBeforeFade, const int framesAfterFade)
: framesBeforeFade(framesBeforeFade)
, framesAfterFade(framesAfterFade)
, framesFading(256)
{
  reset();
}

FadeStatus FadePainter::calcStatus(int frameNum) const {
  FadeStatus s;
  if (frameNum == 0) {
    s = FadeStatus::Idle;
  } else if (frameNum < framesBeforeFade) {
    s = FadeStatus::BeforeFading;
  } else if (frameNum < framesBeforeFade + framesFading) {
    s = FadeStatus::Fading;
  } else if (frameNum < framesBeforeFade + framesFading + framesAfterFade) {
    s = FadeStatus::AfterFading;
  } else {
    s = FadeStatus::Ended;
  }
  return s;
}

bool FadePainter::draw() {
  status = calcStatus(frameCounter++);
  if (status == FadeStatus::Fading) {
    fade();
  }
  return status != FadeStatus::Ended;
}

void FadePainter::reset() {
  frameCounter = 0;
  status = calcStatus(frameCounter);
}

void FadePainter::fade() {
  ofPushStyle();
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofSetColor(ofColor(ofColor::white,1));
  ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
  ofPopStyle();
}

FadeStatus FadePainter::getStatus() const {
  return status;
}

string FadePainter::getStatusString() const {
  string s;
  switch (status) {
  case FadeStatus::Idle:
    s = "Idle";
    break;
  case FadeStatus::BeforeFading:
    s = "BeforeFading";
    break;
  case FadeStatus::Fading:
    s = "Fading";
    break;
  case FadeStatus::AfterFading:
    s = "AfterFading";
    break;
  case FadeStatus::Ended:
    s = "Ended";
    break;
  }
  return s;
}
