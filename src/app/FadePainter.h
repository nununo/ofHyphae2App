//
//  FadePainter.h
//  rhizopusApp
//
//  Created by Nuno on 27/06/2021.
//

#ifndef FadePainter_h
#define FadePainter_h

#include "ofMain.h"

enum class FadeStatus : char {Idle, BeforeFading, Fading, AfterFading, Ended};

class FadePainter {
  const int framesBeforeFade;
  const int framesFading;
  const int framesAfterFade;
  
  int frameCounter;
  FadeStatus status;

  FadeStatus calcStatus(int frameNum) const;
  void fade();
public:
  FadePainter(const int secondsBeforeFade, const int secondsAfterFade);
  bool draw();
  void reset();
  string getStatusString() const;
};

#endif /* FadePainter_h */
