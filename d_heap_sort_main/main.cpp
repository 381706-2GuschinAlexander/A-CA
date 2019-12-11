#include "d_heap_sort.h"

int main()
{
  std::vector<int> a{32, 24, 2, 6, 23, 4, 151, 2};
  dHeapSort(a, 3);
  
  std::cout << "complete";
	return 0;
}