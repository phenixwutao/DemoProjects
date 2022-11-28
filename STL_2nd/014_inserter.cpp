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
  /*******************************************************************************************
   * back_inserter(container)  Appends in the same order by using push_back(val)
   * front_inserter(container) Inserts at the front in reverse order by using push_front(val)
   * inserter(container,pos)   Inserts at pos (in the same order) by using insert(pos,val)
   *******************************************************************************************/
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

  unsigned int n = std::thread::hardware_concurrency();
  std::cout << n << " concurrent threads are supported.\n";
  
  printf("please enter some strings, press Ctrl-D to stop\n");

  vector<string> v1;
  copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v1));
  sort(v1.begin(), v1.end());
  unique_copy(v1.begin(), v1.end(), ostream_iterator<string>(cout, "\n"));
	    
  return 0;
}


