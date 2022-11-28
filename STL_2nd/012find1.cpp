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
  list<int> coll;
  for(int i=20; i<=40; ++i)
    coll.push_back(i);

  auto findListValue = [&](int x){ return find(coll.begin(), coll.end(), x); };
  
  auto pos3 = findListValue(3);
  reverse(pos3, coll.end());

  auto pos25 = findListValue(25);
  auto pos35 = findListValue(35);

  cout << "max: "<< *max_element(pos25, pos35) << endl; // exclude the last element

  cout << "max: "<< *max_element(pos25, ++pos35) << endl; // include the last element

  auto posit = std::find_if(coll.begin(), coll.end(), [](int x) {return x==25 || x==35;});
  if (*posit ==25)
    {
      pos25 = posit;
    }
  else if (*posit == 35)
    {
      pos35 = posit;
    }
  cout << *pos25 << ", " << *pos35 << endl;
  return 0;
}


