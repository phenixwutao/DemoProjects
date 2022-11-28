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

#include <functional> // ref wrapper std::ref(), predefined functors

#include <algorithm> // utility function min, max

#include <utility> // relation operations rel_ops

#include <chrono> // time and clocks


#include "util.hpp"
using namespace std;
using namespace LFen;

class AddValue
{
private:
  int ivalue = 0;
public:
  AddValue(int x) : ivalue(x) {}
  void operator()(int& e) const
  {
    e += ivalue;
  }
};

int main()
{
  list<int> coll;
  // insert elements from 1 to 9
  for (int i=1; i<=9; ++i)
    {
    coll.push_back(i);
    }
  for_each(coll.begin(), coll.end(), AddValue(10));
  PrintAll(coll, "add 10");
  
  for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
  PrintAll(coll, "add 1st value");
  return 0;
}


