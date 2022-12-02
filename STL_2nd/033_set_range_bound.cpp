#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>


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
  set<int> c;
  c.insert(1);
  c.insert(2);
  c.insert(4);
  c.insert(5);
  c.insert(6);
  cout << "lower bound " << *c.lower_bound(3) << endl;
  cout << "upper bound " << *c.upper_bound(3) << endl;
  cout << "equal range first " << *c.equal_range(3).first << endl;
  cout << "equal range second " << *c.equal_range(3).second << endl;

  cout << "lower bound " << *c.lower_bound(5) << endl;
  cout << "upper bound " << *c.upper_bound(5) << endl;
  cout << "equal range first " << *c.equal_range(5).first << endl;
  cout << "equal range second " << *c.equal_range(5).second << endl;

  // - descending order
  set<int,greater<int>> coll1;
  // insert elements in random order using different member functions
  coll1.insert({4,3,5,1,6,2});
  coll1.insert(5);
  // print all elements
  for (int elem : coll1) {
    cout << elem << ' ';
  }
  cout << endl;
  
  // insert 4 again and process return value
  auto status = coll1.insert(4);
  if (status.second) {
    cout << "4 inserted as element "
	 << distance(coll1.begin(),status.first) + 1 << endl;
  }
  else {
    cout << "4 already exists" << endl;
  }
  // assign elements to another set with ascending order
  set<int> coll2(coll1.cbegin(),coll1.cend());
  
  // print all elements of the copy using stream iterators
  copy (coll2.cbegin(), coll2.cend(),
	ostream_iterator<int>(cout," "));
  cout << endl;

  // remove all elements up to element with value 3 (up to 3, but not including 3)
  coll2.erase (coll2.begin(), coll2.find(3));
  
  // remove all elements with value 5
  int num;
  num = coll2.erase (5);
  cout << num << " element(s) removed" << endl;
  
  // print all elements
  copy (coll2.cbegin(), coll2.cend(),
	ostream_iterator<int>(cout," "));
  cout << endl;
  
  return 0;
}


