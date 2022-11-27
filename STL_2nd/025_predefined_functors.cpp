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
  deque<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
  transform (coll.cbegin(),coll.cend(), // source
	     coll.begin(), // destination
	     negate<int>()); // operation
  PrintAll(coll, "after negate");
  
  transform (coll.cbegin(),coll.cend(), // first source
	     coll.cbegin(),             // second source
	     coll.begin(),              // destination
	     multiplies<int>());        // operation
  PrintAll(coll, "after multiplies");
  
  return 0;
}


