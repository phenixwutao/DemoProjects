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

bool isPrime(int num)
{
  num = abs(num);
  if (num == 0 || num == 1)
    return false;

  int divisor = 1;
  for(divisor = num/2; num%divisor != 0; --divisor)
    {
      cout << "num " << num<< ", divisor " << divisor << endl;
    }
  cout << "num " << num<< ", divisor " << divisor << endl;
  return divisor == 1;
}

int main()
{
  list<int> coll;
  for(int i=24; i<=30; ++i)
    coll.push_back(i);

  auto pos = std::find_if(coll.cbegin(), coll.cend(), isPrime);

  if (pos != coll.end())
    {
      cout << "1st prime number is: " << *pos << endl;
    }
  else
    {
      cout << "no prime number" << endl;
    }
  return 0;
}


