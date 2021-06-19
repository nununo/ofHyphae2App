//
//  Range.h
//  rhizopusApp
//
//  Created by Nuno on 20/06/2021.
//

#ifndef Range_h
#define Range_h

class Range {
public:
  double min;
  double max;
};

inline std::ostream& operator<<(std::ostream &strm, const Range &r) {
  return strm << "Range(" << r.min << ", " << r.max << ")";
}

#endif /* Range_h */
