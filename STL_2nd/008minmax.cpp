#include <iostream>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

#include <climits> // old number limit
#include <cfloat>  // old float limit
#include <limits> // C++11 limit header

#include <functional>
#include <algorithm>

using namespace std;


bool lessthanptr(int* a, int* b)
{
  return *a < *b;
}

int main()
{
  int x = 17;
  int y = 42;
  int z = 3;
  int* px = &x;
  int* py = &y;
  int* pz = &z;
  // call max() with special comparison function
  int* pmax = std::max (px, py, lessthanptr);
  cout << "pmax " << *pmax << endl;

  // call minmax() for initializer list with special comparison function
  std::pair<int*,int*> extremes = std::minmax ({px, py, pz},
					       lessthanptr);
  cout << *extremes.first << ", " << *extremes.second << endl;

  auto extremes2 = std::minmax ({px, py, pz}, [](int*a, int*b) {
    return *a < *b;
    });
  cout << *extremes2.first << ", " << *extremes2.second << endl;
  return 0;  
}


