#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
void dHeapSort(std::vector<T>& vec, int d) {
  int n = vec.size();
  for (int i = n - 1; i >= 0; --i) dive(vec, d, i, n);
  while (n > 1) {
    --n;
    std::swap(vec[0], vec[n]);
    dive(vec, d, 0, n);
  }
  n = vec.size();
  for (int i = 0; i < n / 2; ++i) std::swap(vec[i], vec[n - i - 1]);
}

template <class T>
void dive(std::vector<T>& vec, int d, int i, int size) {
  int c = minChild(vec, d, i, size);
  while (c != 0 && vec[c] < vec[i]) {
    std::swap(vec[c], vec[i]);
    i = c;
    c = minChild(vec, d, i, size);
  }
}

template <class T>
int minChild(std::vector<T>& vec, int d, int i, int size) {
  int c = -1;
  if (i * d + 1 >= size)
    c = 0;
  else {
    int first_child = i * d + 1;
    int last_child = std::min((i + 1) * d, size - 1);
    T min_key = vec[first_child];
    c = first_child;
    for (int k = first_child + 1; k <= last_child; ++k)
      if (vec[k] < min_key) {
        min_key = vec[k];
        c = k;
      }
  }
  return c;
}