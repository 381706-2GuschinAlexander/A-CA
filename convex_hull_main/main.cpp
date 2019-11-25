#include "convex_hull.h"

int main()
{
  std::vector<Point> A{Point(1, 4),  Point(-1, 5), Point(1, 3), Point(3, 4),
                       Point(-2, 4), Point(-1, 2), Point(1, -1), Point(1, 2)};
  std::vector<Point> res(createHull(A));
  std::cout << "complete\n";
	return 0;
}