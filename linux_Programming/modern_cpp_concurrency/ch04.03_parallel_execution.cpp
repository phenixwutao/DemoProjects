#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers
#include <exception>

#include <execution> // parallel execution policy

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

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  std::vector<int> vec{1,2,3,4,5};
  std::mutex mut;
  int sum1 = 0;
  // Parallel execution
  std::for_each(std::execution::par, vec.begin(), vec.end(), [&](int i)
                { 
                  std::lock_guard<std::mutex> lock(mut);
                  sum1 += i; 
                });
  std::cout << "sum1=" << sum1 << '\n';

  // Parallel and vectorized execution with a possible deadlock
  int sum2 = 0;
  std::for_each(std::execution::par_unseq, vec.begin(), vec.end(), [&](int i)
                { 
                  std::lock_guard<std::mutex> lock(mut);
                  sum2 += i; 
                });
  std::cout << "sum2=" << sum2 << '\n';

  // Parallel and vectorized execution without a deadlock, using atomic variable
  std::atomic<int> sum3(0);
  std::for_each(std::execution::par_unseq, vec.begin(), vec.end(), [&](int i)
                { 
                  sum3 += i; 
                });
  std::cout << "sum3=" << sum3 << '\n';
  return 0;
}

