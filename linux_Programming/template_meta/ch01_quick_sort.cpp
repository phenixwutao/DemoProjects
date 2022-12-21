#include <iostream>

using namespace std;

using swap_fn    = void(*) (void*, const int i, const int j);
using compare_fn = bool(*) (void*, const int i, const int j);

void swap_int(void* arr, const int i, const int j)
{
  int* iarr = (int*)arr;
  int t = iarr[i];
  iarr[i] = iarr[j];
  iarr[j] = t;
}

bool lessthan_int(void* arr, const int i, const int j)
{
  int* iarr = (int*) arr;
  return iarr[i] < iarr[j];
}


int partition(void* arr, const int low, const int high, compare_fn compfunc, swap_fn swapfunc)
{
  int i = low-1;
  for(int j = low; j <= high-1; ++j)
  {
    if (compfunc(arr, j, high))
    {
      ++i;
      swapfunc(arr, i, j);
    }
  }
  swapfunc(arr, i+1, high);
  return i + 1;
}

void quicksort(void* arr, const int low, const int high, compare_fn compfunc, swap_fn swapfunc)
{
  if (low < high)
  {
    const int pi = partition(arr, low, high, compfunc, swapfunc);
    quicksort(arr, low, pi-1, compfunc, swapfunc);
    quicksort(arr, pi+1, high, compfunc, swapfunc);
  }
}

int main()
{
  int arr[] = {13,1,8,3,5,2,15};
  int size = sizeof(arr)/sizeof(arr[0]);
  quicksort(arr, 0, size-1, lessthan_int, swap_int);
  for(auto i : arr)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  return 0;
}