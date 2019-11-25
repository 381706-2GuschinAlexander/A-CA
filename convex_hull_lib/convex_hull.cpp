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
  dHeapSort(tmp, 2);
  auto it = tmp.begin();

  std::vector<Point> st;
  st.push_back(*(it++));
  st.push_back(*(it++));
  auto st_iter_first = st.end() - 2; 
  auto st_iter_second = st.end() - 1;

  while (it != tmp.end()) {
    st_iter_first = st.end() - 2;
    st_iter_second = st.end() - 1;

    double ul = st_iter_second->x -st_iter_first->x;
    double ur = it->x - st_iter_first->x;
    double dl = st_iter_second->y - st_iter_first->y;
    double dr = it->y - st_iter_first->y;
    if (ul * dr - ur * dl > 0)
      st.push_back(*(it++));
    else if (st.size() >= 3) {
      st.pop_back();
      continue;
    } else {
      st.pop_back();
      st.push_back(*(it++));
    }
  }
  return st;
}
