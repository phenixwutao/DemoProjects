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
  forward_list<int> l1 = { 1, 2, 3, 4, 5 };
  forward_list<int> l2 = { 97, 98, 99 };
  forward_list<int> list3 = l1;
  forward_list<int> list4 = l2;
  // find 3 in l1
  auto pos1=l1.before_begin();
  for (auto pb1=l1.begin(); pb1 != l1.end(); ++pb1, ++pos1) {
    if (*pb1 == 3) {
      break; // found
    }
  }

  // find 99 in l2
  auto pos2=l2.before_begin();
  for (auto pb2=l2.begin(); pb2 != l2.end(); ++pb2, ++pos2) {
    if (*pb2 == 99) {
      break; // found
    }
  }
  // splice 3 from l1 to l2 before 99
  l1.splice_after(pos2, l2, // destination
		  pos1);    // source : move single element from list1 to list2

  PrintAll(l1, "list 1");
  PrintAll(l2, "list 1");

  // create two forward lists
  forward_list<int> list1 = { 1, 2, 3, 4 };
  forward_list<int> list2 = { 77, 88, 99 };
  PrintAll(list1, "list 1");
  PrintAll(list2, "list 2");
  
  // insert six new element at the beginning of list2
  list2.insert_after(list2.before_begin(),99);
  list2.push_front(10);
  list2.insert_after(list2.before_begin(), {10,11,12,13} );
  PrintAll(list2, "list 2");

  // insert all elements of list2 at the beginning of list1
  list1.insert_after(list1.before_begin(),
		     list2.begin(),list2.end());
  PrintAll(list1, "list 1");
  PrintAll(list2, "list 2");

  // delete second element and elements after element with value 99
  list2.erase_after(list2.begin());
  list2.erase_after(find(list2.begin(),list2.end(),
			 99),
		    list2.end());

  PrintAll(list1, "erase list 1");
  PrintAll(list2, "erase list 2");
  
  // sort list1, assign it to list2, and remove duplicates
  list1.sort();
  list2 = list1;
  list2.unique();
  PrintAll(list1, "sort list 1");
  PrintAll(list2, "sort list 2");

  // merge both sorted lists into list1
  list1.merge(list2);
  PrintAll(list1, "merge list 1");
  PrintAll(list2, "merge list 2");

  int* pR = new int;
  *pR = 4;
  return 0;
}
