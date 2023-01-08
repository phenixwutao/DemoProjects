#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
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

void calcProducts(std::packaged_task<int(int,int)>& task, 
                  const std::vector<std::pair<int,int>>& pairs)
{
  for(auto& pair : pairs)
  {
    auto fut = task.get_future();
    task(pair.first, pair.second);
    std::cout << "pair.first: " << pair.first 
    << " * pair.second: " << pair.second 
    << " = fut.get(): " << fut.get() << '\n';

    task.reset(); // reuse packaged task;
  }
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::vector<pair<int, int>> allPairs;
  allPairs.push_back(std::make_pair(1,2));
  allPairs.push_back(std::make_pair(2,3));
  allPairs.push_back(std::make_pair(3,4));
  allPairs.push_back(std::make_pair(4,5));

  std::packaged_task<int(int, int)> task([](int fir, int sec)
                                         { return fir * sec; });
  calcProducts(task, allPairs); // calculate the products in main thread
  std::cout << '\n';

  std::cout << "using child thread do the calculation\n";
  std::thread thr(calcProducts, std::ref(task), allPairs);
  thr.join();
  return 0;
}

