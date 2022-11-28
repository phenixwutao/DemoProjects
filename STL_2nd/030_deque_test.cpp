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
  // create empty deque of strings
  deque<string> coll;
  
  // insert several elements
  coll.assign (3, string("string"));
  coll.push_back ("last string");
  coll.push_front ("first string");
  
  // print elements separated by newlines
  copy (coll.cbegin(), coll.cend(),
	ostream_iterator<string>(cout,"\n"));
  cout << endl;
  
  // remove first and last element
  coll.pop_front();
  coll.pop_back();

  // insert "another" into every element but the first
  for (unsigned i=1; i<coll.size(); ++i) {
    coll[i] = "another " + coll[i];
  }
  PrintAll(coll, "-----coll modified");
  
  // change size to four elements
  coll.resize (5, "resized string");
  PrintAll(coll, "-----coll resize");
  
  // print elements separated by newlines
  copy (coll.cbegin(), coll.cend(),
	ostream_iterator<string>(cout,"\n"));

  return 0;
}


