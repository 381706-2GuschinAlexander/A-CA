#include "point.h"

Point::Point(int _x, int _y) {
  x = _x;
  y = _y;
  angle = 0;
  length = 0;
}

Point::Point(const Point& A) {
  x = A.x;
  y = A.y;
  angle = A.angle;
  length = A.length;
}

Point& Point::operator=(const Point& A) {
  x = A.x;
  y = A.y;
  angle = A.angle;
  length = A.length;
  return *this;
}

bool AngleComp::operator()(const Point& A,
                               const Point& B) {
  if (A.angle < B.angle)
    return true;
  else if (A.angle == B.angle && A.length < B.length)
    return true;
  else
    return false;
}
