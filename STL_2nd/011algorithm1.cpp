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
  vector<int> coll = {2,5,4,1,6,3};
  for(auto it : coll)
    cout << it << ' ';
  cout << endl;

  auto minpos = min_element(coll.cbegin(), coll.cend());
  cout << "min " << *minpos << endl;
  auto maxpos = max_element(coll.cbegin(), coll.cend());
  cout << "max " << *maxpos << endl;

  std::sort(coll.begin(), coll.end());
  for(auto it : coll)
    cout << it << ' ';
  cout << endl;

  auto pos3 = find(coll.begin(), coll.end(), 3);
  reverse(pos3,coll.end());
  for(auto it : coll)
    cout << it << ' ';
  cout << endl;

  return 0;
}


