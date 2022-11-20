#include <iostream>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

#include <climits> // old number limit
#include <cfloat>  // old float limit
#include <limits> // C++11 limit header

using namespace std;

template<typename T1, typename T2>
typename std::common_type<T1,T2>::type min(const T1& x, const T2& y)
{
  return x < y ? x : y ;
}

/*
template<typename T>
void foo(const T& val)
{
  std::cout << (std::is_pointer<T>::value ? *val : val) << endl;
}
*/

int main()
{
  cout << min(2,4) << endl;

  return 0;  
}


