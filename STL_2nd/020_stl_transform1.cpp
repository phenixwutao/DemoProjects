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

#include <functional> // ref wrapper std::ref()

#include <algorithm> // utility function min, max

#include <utility> // relation operations rel_ops

#include <chrono> // time and clocks

#include "util.hpp"

using namespace std;
using namespace LFen;

int square1(int v)
{
  int sqr = v * v;
  //  cout << "sqr is: " << sqr << endl;
  return sqr;
}

int main()
{
  std::set<int> coll1;
  std::vector<int> coll2;
  for(int i = 1; i <= 9; ++i)
    coll1.insert(i);

  PrintAll(coll1, "init set");

  transform(coll1.cbegin(), coll1.cend(), // source
	    std::back_inserter(coll2),  // destination
	    square1); // operation

  PrintAll(coll2, "transform vector back_inserter");
  
  return 0;
}


