#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>

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

int main()
{
  const vector<int> v1 {1,2,3};
  const vector<int> v2 =  {1,2,3};
  std::unordered_set<string>      w = { "hello", string(), ""};
  std::unordered_set<std::string> w2 = { "hello", std::string(), "" };
  vector<string> v3(w.begin(), w.end());
  PrintAll(v3, "v3 after copy");

  vector<string> v4(std::make_move_iterator(w2.begin()),
		    std::make_move_iterator(w2.end()));
  PrintAll(v4, "v4 after copy");
  
  PrintAll(w2, "w2 after move");

  vector<int> v5 = std::move(v2);
  PrintAll(v5, "v5 after move");
  return 0;
}


