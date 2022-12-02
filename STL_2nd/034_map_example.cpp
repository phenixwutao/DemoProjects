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
#include <iomanip>

#include <functional> // ref wrapper std::ref()

#include <algorithm> // utility function min, max

#include <utility> // relation operations rel_ops

#include <chrono> // time and clocks


#include "util.hpp"
using namespace std;
using namespace LFen;

int main()
{
  map<string, double> coll {{"tim", 9.9},{"paige", 8.8},{"tala", 3.3}};

  for_each(coll.begin(), coll.end(), [](pair<const string, double>& item)
  {
    item.second *= item.second;
  });

  for_each(coll.begin(), coll.end(), [](const map<string, double>::value_type& item)
  {
    cout << item.first << " " << item.second << endl;
  });


  using StringFloatMap = map<string,float>;
  StringFloatMap stocks;
  stocks["BASF"] = 360.50;
  stocks["VW"] = 413.50;
  stocks["Daimler"] = 819.00;
  stocks["BMW"] = 834.00;
  stocks["Siemens"] = 842.20;
  StringFloatMap::iterator pos;
  cout << left;

  for( pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
      cout << "stock: " << setw(12) << pos->first << " price " << pos->second << endl;
    }
  cout << endl;
  for( pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
      pos->second *= 2;
    }  
  for( pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
      cout << "stock: " << setw(12) << pos->first << " price " << pos->second << endl;
    }

  // rename key from "VW" to "Volkswagen"
  // - provided only by exchanging element
  stocks["Volkswagen"] = stocks["VW"];
  stocks.erase("VW");

  for( pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
      cout << "stock: " << setw(12) << pos->first << " price " << pos->second << endl;
    }

  cout << R"(------------ test multimap -----------)" << endl;;
  multimap<string, string> dict;
  dict.insert({
      {"day","Tag"}, {"strange","fremd"},
      {"car","Auto"}, {"smart","elegant"},
      {"trait","Merkmal"}, {"strange","seltsam"},
      {"smart","raffiniert"}, {"smart","klug"},
      {"clever","raffiniert"}
    });


  cout << R"(print all elements)" << endl;
  cout.setf (ios::left, ios::adjustfield);
  cout << ' ' << setw(10) << "english "
       << "german " << endl;
  cout << setfill('-') << setw(20) << ""
       << setfill(' ') << endl;
  for ( const auto& elem : dict ) {
    cout << ' ' << setw(10) << elem.first
	 << elem.second << endl;
  }
  cout << endl;

  cout << R"(print all values for key "smart")" << endl;;
  string word("smart");
  cout << word << ": " << endl;
  for (auto pos = dict.lower_bound(word);
       pos != dict.upper_bound(word);
       ++pos) {
    cout << " " << pos->second << endl;
  }
  cout << R"(print all keys for value "raffiniert")" << endl;
  word = ("raffiniert");
  cout << word << ": " << endl;
  for (const auto& elem : dict) {
    if (elem.second == word) {
      cout << " " << elem.first << endl;
    }
  }

  cout << R"(1 map with floats as key and value)" << endl;
  cout << R"(1 - initializing keys and values are automatically converted to float)" << endl;
  map<float,float> coll2 = { {1,7}, {2,4}, {3,2}, {4,3},
			    {5,6}, {6,1}, {7,3} };
  
  cout << R"(2 search an element with key 3.0 (logarithmic complexity)) :class method)" << endl;
  auto posKey = coll2.find(3.0);
  if (posKey != coll2.end()) {
    cout << "key 3.0 found ("
	 << posKey->first << ":"
	 << posKey->second << ")" << endl;
  }
  cout << R"(3 search an element with value 3.0 (linear complexity)) : general algorithm)" << endl;
  auto posVal = find_if(coll2.begin(),coll2.end(),
			[] (const pair<float,float>& elem) {
			  return elem.second == 3.0;
			});
  if (posVal != coll2.end()) {
    cout << "value 3.0 found ("
	 << posVal->first << ":"
	 << posVal->second << ")" << endl;
  }
  
  return 0;
}


