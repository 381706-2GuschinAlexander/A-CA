

struct Point {
  double x;
  double y;
  double angle;
  double length;
  Point(int _x = 0, int _y = 0);
  Point(const Point& A);
  Point& operator=(const Point& A);
};

struct AngleComp {
  bool operator()(const Point& A, const Point& B);
};