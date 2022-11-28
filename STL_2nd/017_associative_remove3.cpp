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
  set<int> coll = {1,2,3,4,5,6,7,8,9};
  copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;

  int num = coll.erase(3);
  cout << "number of elements removed: " << num << endl; 
  copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
  
  return 0;
}


