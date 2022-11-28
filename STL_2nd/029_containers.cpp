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

#include <cstring> // C-stype string functions, e.g. strcpy

#include <numeric> // accumulate function

#include "util.hpp"
using namespace std;
using namespace LFen;

int main()
{
  std::array<int, 4> x = {1}; // 1st is 1, the rest are zeros
  PrintAll(x, "test array");

  //std::array<int, 2> x = {1,2,3}; // compiler error

  vector<int> v1({1,2,3,4}); // ok
  vector<int> v2{1,2,3,4}; // ok
  PrintAll(v2, "test v2");

  std:array<char, 41> a;
  strcpy(&a[0], "hello world");
  printf("%s\n", &a[0]);
  
  strcpy(a.data(), "2 hello world");
  printf("%s\n", a.data());  // C-style pointer

  typedef std::array<std::string,5> FiveStrings;
  FiveStrings a5 = { "hello", "nico", "how", "are", "you" };
  cout << std::get<1>(a5) << endl;

  array<int,10> a3 = { 11, 22, 33, 44 };

  a3.back() = 9999999;
  a3[a3.size()-2] = 42;
  PrintAll(a3, "a3 init");

  cout << "sum: "
       << accumulate(a3.begin(),a3.end(),0)
       << endl;
  PrintAll(a3, "a3 sum");
  
  transform(a3.begin(),a3.end(), // source
	    a3.begin(), // destination
	    negate<int>()); // operation
  PrintAll(a3, "a3 negate");
  
  std::vector<int> v5(5); // creates a vector and initializes it with five values
                       // (calls five times the default constructor of type T)
  PrintAll(v5, "v5 print");

  vector<int> v6(6,3);
  PrintAll(v6, "v6 print");
  vector<int> v7( {3,2,1,4,5,6,7,8} );
  PrintAll(v7, "v7 print");
  cout << v7.size() << " , " << v7.capacity() << endl;
  v7.shrink_to_fit();
  cout << v7.size() << " , " << v7.capacity() << endl;

  list<int> lst1 = {10,11,12};
  v7.assign(lst1.begin(), lst1.end());
  PrintAll(v7, "v7 assign");
  cout << v1.front() << ", " << v7.back() << endl;

  // use algorithm to remove element
  v7.erase(remove(v7.begin(),v7.end(),
		    12),
	     v7.end());
  PrintAll(v7, "v7 after remove");

  std::vector<char> v8(41); // create static array of 41 chars
  strcpy(v8.data(),"hello, world"); // copy a C-string into the array
  printf("v8: %s\n", v8.data()); // print contents of the array as C-string


  // create empty vector for strings
  vector<string> sentence;
  
  // reserve memory for five elements to avoid reallocation
  sentence.reserve(5);
  
  // append some elements
  sentence.push_back("Hello,");
  sentence.insert(sentence.end(),{"how","are","you","?"});
  
  // print elements separated with spaces
  copy (sentence.cbegin(), sentence.cend(),
	ostream_iterator<string>(cout," "));
  
  // print "technical data"
  cout << " max_size(): " << sentence.max_size() << endl;
  cout << " size(): " << sentence.size() << endl;
  cout << " capacity(): " << sentence.capacity() << endl;
  // swap second and fourth element
  swap (sentence[1], sentence[3]);
  PrintAll(sentence, "sentence print 1");

  // insert element "always" before element "?"
  sentence.insert (find(sentence.begin(),sentence.end(),"?"),
		   "always");
  PrintAll(sentence, "sentence print 2");
  
  // assign "!" to the last element
  sentence.back() = "!";
  PrintAll(sentence, "sentence print 3");
  
  cout << " size(): " << sentence.size() << endl;
  cout << " capacity(): " << sentence.capacity() << endl;
  sentence.pop_back();
  sentence.pop_back();
  cout << " size(): " << sentence.size() << endl;
  cout << " capacity(): " << sentence.capacity() << endl;
  sentence.shrink_to_fit();
  cout << " size(): " << sentence.size() << endl;
  cout << " capacity(): " << sentence.capacity() << endl;
  return 0;
}


