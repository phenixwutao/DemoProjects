#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <forward_list>

#include <iterator>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

#include <climits> // old number limit
#include <cfloat>  // old float limit
#include <limits> // C++11 limit header
#include <cstdlib> // math libs function e.g. abs()

#include <functional> // ref wrapper std::ref()

#include <algorithm> // utility function min, max

#include <utility> // relation operations rel_ops

#include <chrono> // time and clocks


#include "util.hpp"
using namespace std;
using namespace LFen;

int main()
{
  deque<int> coll;
  for(int i=1; i<=9; ++i) {
    coll.push_back(i);
    coll.push_front(i);
  }
  PrintAll(coll, "coll default without sort");
  sort(coll.begin(), coll.end());
  PrintAll(coll, "coll sort default");
  
  sort(coll.begin(), coll.end(), greater<int>());
  PrintAll(coll, "coll sort greater");
  return 0;
}


