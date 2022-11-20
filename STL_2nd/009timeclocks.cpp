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
#include <chrono>

using namespace std;


bool lessthanptr(int* a, int* b)
{
  return *a < *b;
}

int main()
{
  std::chrono::seconds time(20);
  std::chrono::milliseconds time1(20);

  return 0;  
}


