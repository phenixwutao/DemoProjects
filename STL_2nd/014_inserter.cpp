#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <forward_list>

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
  list<int> coll1 = {1,2,3,4,5,6,7,8,9};
  vector<int> coll2(coll1.size());
  copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));

  deque<int> coll3;
  copy(coll1.cbegin(), coll1.cend(), std::front_inserter(coll3));
  
  set<int> coll4;
  copy(coll1.cbegin(), coll1.cend(), std::inserter(coll4, coll4.begin()));
  
  for(auto it : coll4)
    printf("%d ", it);
  cout << endl;
	    
  return 0;
}


