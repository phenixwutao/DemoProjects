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

void print(int e)
{
  cout << e << ' ';
}

int main()
{
  vector<int> coll = {1,2,3,4,5,6,7,8};
  for_each(coll.cbegin(), coll.cend(), print);
  cout << endl;
  
  for_each(coll.cbegin(), coll.cend(), [](int e){
    cout << e << ", ";}
    );
  cout << endl;
  return 0;
}


