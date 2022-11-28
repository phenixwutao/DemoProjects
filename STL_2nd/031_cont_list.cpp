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

void printLists (const list<int>& l1, const list<int>& l2)
{
  cout << "list1: ";
  copy (l1.cbegin(), l1.cend(), ostream_iterator<int>(cout," "));
  cout << endl << "list2: ";
  copy (l2.cbegin(), l2.cend(), ostream_iterator<int>(cout," "));
  cout << endl << endl;
}


int main()
{

  // create two empty lists
  list<int> list1, list2;
  
  // fill both lists with elements
  for (int i=0; i<6; ++i) {
    list1.push_back(i);
    list2.push_front(i);
  }
  printLists(list1, list2);
  
  // insert all elements of list1 before the first element with value 3 of list2
  // - find() returns an iterator to the first element with value 3
  list2.splice(find(list2.begin(),list2.end(), // destination position
		    3),
	       list1); // source list
  
  printLists(list1, list2);
  
  // move first element of list2 to the end
  list2.splice(list2.end(), // destination position
	       list2, // source list
	       list2.begin()); // source position

  printLists(list1, list2);
  
  // sort second list, assign to list1 and remove duplicates
  list2.sort();
  list1 = list2;
  list2.unique();
  printLists(list1, list2);
  
  // merge both sorted lists into the first list
  list1.merge(list2); // move list2 into list1, list2 is empty now
  
  printLists(list1, list2);

  std::forward_list<int> fwlist = { 1, 2, 3 };
  // insert 77, 88, and 99 at the beginning:
  fwlist.insert_after (fwlist.before_begin(), // position
		       { 77, 88, 99 } ); // values
  PrintAll(fwlist, "fw list after insert_after");

  forward_list<int> list = { 1, 2, 3, 4, 5, 97, 98, 99 };
  // find the position before the first even element
  auto posBefore = list.before_begin();
  for (auto pos=list.begin(); pos!=list.end(); ++pos, ++posBefore) {
    if (*pos % 2 == 0) {
      break; // element found
    }
  }
  // and insert a new element in front of the first even element
  list.insert_after(posBefore,42);
  PrintAll(list, "after insert 42");
  return 0;
}

