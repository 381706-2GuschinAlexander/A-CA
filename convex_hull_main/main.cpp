#include <random>
#include <ctime>
#include "convex_hull.h"

void GeneratePoint(std::vector<Point>& res, int size) {
  // std::vector<Point> res(size);
  std::mt19937 gen(time(0));
  for (int i = 0; i < size; ++i) {
    int x = (gen() - 100) % 100;
    int y = (gen() - 100) % 100;
    Point tmp(x, y);
    res[i] = tmp;
  }
  // return res;
}

int main()
{
  /*std::vector<Point> A{Point(1, 4),  Point(-1, 5), Point(1, 3), Point(3, 4),
                       Point(-2, 4), Point(-1, 2), Point(1, -1), Point(1, 2)};*/

  std::vector<Point> A1(100000);
  GeneratePoint(A1, 100000);

  std::vector<Point> A2(200000);
  GeneratePoint(A2, 200000);

  std::vector<Point> A3(300000);
  GeneratePoint(A3, 300000);

  std::vector<Point> A4(400000);
  GeneratePoint(A4, 400000);

  std::vector<Point> A5(500000);
  GeneratePoint(A5, 500000);

  time_t start, end;
  start = clock();
  std::vector<Point> res1(createHull(A1));
  end = clock();
  std::cout <<"100000: " <<static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  std::vector<Point> res2(createHull(A2));
  end = clock();
  std::cout << "200000: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
            << std::endl;

  start = clock();
  std::vector<Point> res3(createHull(A3));
  end = clock();
  std::cout << "300000: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
            << std::endl;

  start = clock();
  std::vector<Point> res4(createHull(A4));
  end = clock();
  std::cout << "400000: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
            << std::endl;

  start = clock();
  std::vector<Point> res5(createHull(A5));
  end = clock();
  std::cout << "500000: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
            << std::endl;

  std::cout << "complete\n";
	return 0;
}