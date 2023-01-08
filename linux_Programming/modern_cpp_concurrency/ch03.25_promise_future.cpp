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

struct Div{
  void operator()(std::promise<int>&& intPromise, int a, int b) const
  {
    intPromise.set_value(a / b);
  }
};

void product(std::promise<int>&& intPromise, int a, int b)
{
  intPromise.set_value(a * b);
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  int a = 20, b = 10;
  std::promise<int> prodPromise;
  std::promise<int> divPromise;
  auto prodFuture = prodPromise.get_future();
  auto divFuture = divPromise.get_future();

  // using thread do the calculation with promise and and pass-in parameters
  std::thread prodThr(product, std::move(prodPromise), a, b);
  std::thread divThr(Div(), std::move(divPromise), a, b);

  std::cout << prodFuture.get() << '\n';
  std::cout << divFuture.get() << '\n';

  prodThr.join();
  divThr.join();
  return 0;
}

