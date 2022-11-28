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
  vector<int> coll1; // empty collection
  vector<int> coll2; // empty collection

  // RUNTIME ERROR:
  // - beginning is behind the end of the range
  vector<int>::iterator pos = coll1.begin();
  reverse (++pos, coll1.end());
  
  // insert elements from 1 to 9 into coll1
  for (int i=1; i<=9; ++i) {
    coll1.push_back (i);
  }
  
  // RUNTIME ERROR:
  // - overwriting nonexisting elements
  copy (coll1.cbegin(), coll1.cend(), // source
	coll2.begin()); // destination

  // RUNTIME ERROR:
  // - collections mistaken
  // - cbegin() and cend() refer to different collections
  copy (coll1.cbegin(), coll2.cend(), // source
	coll1.end()); // destination
  
  return 0;
}


