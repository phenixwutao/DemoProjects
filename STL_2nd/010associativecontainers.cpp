#include <iostream>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <forward_list>

#include <unordered_set>
#include <unordered_map>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

#include <climits> // old number limit
#include <cfloat>  // old float limit
#include <limits> // C++11 limit header

#include <functional>
#include <algorithm>
#include <chrono>

using namespace std;



int main()
{
  multiset<string> cities {
    "Braunschweig", "Hanover", "Frankfurt", "New York",
    "Chicago", "Toronto", "Paris", "Frankfurt"
  };
  // print each element:
  for (const auto& elem : cities) {
    cout << elem << " ";
  }
  cout << endl;

  // insert additional values:
  cities.insert( {"London", "Munich", "Hanover", "Braunschweig"} );
  // print each element:
  for (const auto& elem : cities) {
    cout << elem << " ";
  }
  cout << endl;


  unordered_multiset<string> cities2 {
    "Braunschweig", "Hanover", "Frankfurt", "New York",
    "Chicago", "Toronto", "Paris", "Frankfurt"
  };
  // print each element:
  for (const auto& elem : cities2) {
    cout << elem << " ";
  }
  cout << endl;
  
  // insert additional values:
  cities2.insert( {"London", "Munich", "Hanover", "Braunschweig"} );

  // print each element:
  for (const auto& elem : cities2) {
    cout << elem << " ";
  }
  cout << endl;
  
  return 0;  
}


