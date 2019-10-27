#include "convex_hull.h"

int main()
{
  std::vector<Point> A{Point(1, 4), Point(-1, 5), Point(1, 3), Point(3, 4),
                       Point(-2, 4)};
  std::vector<Point> res(createHull(A));
	return 0;
}