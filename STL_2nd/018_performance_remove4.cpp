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

using namespace std;

int main()
{
  list<int> coll;
  
  // insert elements from 6 to 1 and 1 to 6
  for (int i=1; i<=6; ++i) {
    coll.push_front(i);
    coll.push_back(i);
  }
  
  // remove all elements with value 3 (poor performance)
  coll.erase (remove(coll.begin(),coll.end(), 3),
	      coll.end());
  
  // remove all elements with value 4 (good performance)
  // prefer to use list member function
  coll.remove (4);
  
  return 0;
}


