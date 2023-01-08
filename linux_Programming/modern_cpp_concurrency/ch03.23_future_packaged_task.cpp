#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <deque>
#include <list>
#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>
#include <future>
#include <semaphore>
#include <latch>
#include <barrier>

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

class SumUp{
  public:
  int operator()(int beg, int end)
  {
    long long int sum(0);
    for (int i = beg; i < end; ++i)
      sum += i;

    return sum;
  }
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  SumUp sumup1;
  SumUp sumup2;
  SumUp sumup3;
  SumUp sumup4;

  std::packaged_task<int(int, int)> sumTask1(sumup1);
  std::packaged_task<int(int, int)> sumTask2(sumup2);
  std::packaged_task<int(int, int)> sumTask3(sumup3);
  std::packaged_task<int(int, int)> sumTask4(sumup4);

  auto fut1 = sumTask1.get_future();
  auto fut2 = sumTask2.get_future();
  auto fut3 = sumTask3.get_future();
  auto fut4 = sumTask4.get_future();

  std::deque<std::packaged_task<int(int, int)>> allTasks;
  allTasks.push_back(std::move(sumTask1));
  allTasks.push_back(std::move(sumTask2));
  allTasks.push_back(std::move(sumTask3));
  allTasks.push_back(std::move(sumTask4));

  int beg{1};
  int increment{2500};
  int end = beg + increment;

  while(not allTasks.empty()) {
    std::packaged_task<int(int, int)> myTask = std::move(allTasks.front());
    allTasks.pop_front();
    std::thread sumThread(std::move(myTask), beg, end);
    beg = end;
    end += increment;
    sumThread.detach();
  }

  auto sum = fut1.get() + fut2.get() + fut3.get() + fut4.get();
  std::cout << "sum= " << sum << '\n';

  return 0;
}

