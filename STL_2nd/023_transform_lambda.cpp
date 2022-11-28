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

class Pred
{
private:
  int x = 0;
  int y = 0;
public:
  Pred(int xx, int yy) : x(xx), y(yy) {}
  bool operator()(int i) const // operator must be const 
  {
    return i>x && i <y;
  }
};

int main()
{
  deque<int> coll;
  for(int i=1; i<=9; ++i) {
    coll.push_back(i);
    coll.push_front(i);
  }
  PrintAll(coll, "coll init");

  std::transform(coll.begin(), coll.end(), // source
		 coll.begin(),             // destination
		 [](int i){return i*i;});  // operation
  PrintAll(coll, "coll after transform");

  deque<int> coll2 = { 1, 3, 19, 5, 13, 7, 11, 2, 17 };
  int x = 5;
  int y = 12;
  auto pos = find_if (coll2.cbegin(), coll2.cend(), // range
		      [=](int i) {                  // search criterion
			return i > x && i < y;
		      });
  PrintAll(coll2, "coll2 all elements");
  cout << "lambda first elem > 5 and < 12: " << *pos << endl;

  auto pos2 = find_if(coll2.cbegin(), coll2.cend(), Pred(x,y));
  cout << "Pred first elem > 5 and < 12: " << *pos2 << endl;
  
  auto pos3 = find_if(coll2.cbegin(), coll2.cend(),
		      bind(logical_and<bool>(),
			   bind(greater<int>(), std::placeholders::_1, x),
			   bind(less<int>(),    std::placeholders::_1, y)));
  cout << "Bind first elem > 5 and < 12: " << *pos3 << endl;
  return 0;
}


