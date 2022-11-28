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

#include <functional>

using namespace std;

void func(int x, int y)
{
  cout << x + y << endl;
}


class C
{
public:
  void calc(int x, int y) const
  {
    cout << x - y << endl;
  }
};

int main()
{
  vector<std::function<void(int, int)> > tasks;
  tasks.push_back(func);
  tasks.push_back([](int x, int y) { cout << x * y << endl; });
  for (std::function<void(int, int)> f : tasks)
    {
    f(3, 5);
    }

  std::function<void(const C&, int, int)> mf;
  mf = &C::calc;
  mf(C(), 5, 3);

  std::function<void(const C&, int, int)> mf1;
  mf1 = &C::calc;
  C obj1;
  mf1(obj1, 6, 3);
  return 0;  
}


