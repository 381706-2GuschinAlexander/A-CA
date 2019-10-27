#include "convex_hull.h"

void setAngle(std::vector<Point>& A) {
  auto it = A.begin() + 1;
  for (it; it != A.end(); ++it) {
    it->angle = atan((it->y - A.begin()->y) / (it->x - A.begin()->x));
    if (it->angle < 0) it->angle += M_PI;
    it->length =
        sqrt(pow((it->y - A.begin()->y), 2) + pow((it->x - A.begin()->x), 2));
  }
}

void setFirstPoint(std::vector<Point>& vec) {
  auto swap_iter = vec.begin();
  auto it = vec.begin() + 1;
  for (it; it != vec.end(); ++it) {
    if (it->y < swap_iter->y)
      swap_iter = it;
    else if (it->x < swap_iter->x && it->y == swap_iter->y)
      swap_iter = it;
  }
  std::iter_swap(vec.begin(), swap_iter);
}

std::vector<Point> createHull(const std::vector<Point>& vec) {
  std::vector<Point> tmp(vec);
  setFirstPoint(tmp);
  setAngle(tmp);
  std::sort(tmp.begin() + 1, tmp.end(), AngleComp());
  auto it = tmp.begin();

  std::vector<Point> st;
  st.push_back(*(it++));
  st.push_back(*(it++));
  for (it; it != tmp.end(); ++it) {
  ///
  }
  return st;
}
