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
using namespace std::placeholders;
using namespace LFen;

int main()
{
  set<int, greater<int>> coll1 = {1,2,3,4,5,6,7,8,9};
  deque<int> coll2;
  PrintAll(coll1, "init values");

  transform(coll1.cbegin(), coll1.cend(),     // source
	    back_inserter(coll2),             // destination
	    bind(multiplies<int>(), _1, 10)); // operation
  PrintAll(coll2, "values after transform");

  replace_if(coll2.begin(), coll2.end(),    // range
	     bind(equal_to<int>(), _1, 70), // replace criteria
	     42);                           // new value
  
  PrintAll(coll2, "values after replace");

  // remove if berween 50 and 80
  auto itrm = std::remove_if(coll2.begin(), coll2.end(),  // range
			     bind(logical_and<bool>(),    // remove criteria
				  bind(greater_equal<int>(), _1, 50),
				  bind(less_equal<int>(),    _1, 80)));
  
  coll2.erase(itrm, coll2.end());
  PrintAll(coll2, "values after remove");

  auto f10 = bind(multiplies<int>(), _1, 10);
  cout << "call f10 function: " << f10(3) << endl;
  return 0;
}


