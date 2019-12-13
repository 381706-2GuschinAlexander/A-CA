#include <random>
#include <ctime>
#include <vector>
#include "d_heap_sort.h"

void GenerateInt(std::vector<int>& vec) {
  int size = vec.size();
  std::mt19937 gen(time(0));
  for (int i = 0; i < size; ++i) vec[i] = gen();
}

int main() {
  std::vector<int> A1(100000);
  GenerateInt(A1);

  std::vector<int> A2(200000);
  GenerateInt(A2);

  std::vector<int> A3(300000);
  GenerateInt(A3);

  std::vector<int> A4(400000);
  GenerateInt(A4);

  std::vector<int> A5(500000);
  GenerateInt(A5);

  time_t start, end;
  start = clock();
  dHeapSort(A1, 5);
  end = clock();
  std::cout << "d = 5 100000: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
            << std::endl;

  start = clock();
  dHeapSort(A2, 5);
  end = clock();
  std::cout << "d = 5 200000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  dHeapSort(A3, 5);
  end = clock();
  std::cout << "d = 5 300000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  dHeapSort(A4, 5);
  end = clock();
  std::cout << "d = 5 400000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  dHeapSort(A5, 5);
  end = clock();
  std::cout << "d = 5 500000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  GenerateInt(A1);
  GenerateInt(A2);
  GenerateInt(A3);
  GenerateInt(A4);
  GenerateInt(A5);

  start = clock();
  dHeapSort(A1, 10);
  end = clock();
  std::cout << "d = 10 100000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  dHeapSort(A2, 10);
  end = clock();
  std::cout << "d = 10 200000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  dHeapSort(A3, 10);
  end = clock();
  std::cout << "d = 10 300000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  dHeapSort(A4, 10);
  end = clock();
  std::cout << "d = 10 400000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  start = clock();
  dHeapSort(A5, 10);
  end = clock();
  std::cout << "d = 10 500000: "
            << static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

  std::cout << "complete\n";
  return 0;
}