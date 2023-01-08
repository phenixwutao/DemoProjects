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

std::mutex countMutex;

struct Div
{
  void operator()(std::promise<int>&& intPromise, int a, int b)
  {
    intPromise.set_value(a/b);
  }
};

struct Requestor{
  void operator()(std::shared_future<int> shaFuture)
  {
    std::lock_guard<std::mutex> lock(countMutex);
    std::cout << "threadId(" << std::this_thread::get_id() << "): ";
    std::cout << "20/10= " << shaFuture.get() << '\n';
  }
};
int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::promise<int> divpromise;
  std::future<int> divResult = divpromise.get_future();
  std::cout << "1 divResult.valid() " << divResult.valid() << '\n';

  Div div;
  std::jthread divThread(div, std::move(divpromise), 20, 10);
  std::cout << "2 divResult.valid() " << divResult.valid() << '\n';

  // convert into a shared future, the original future is not valid anymore,
  // it transfers the shared state.
  std::shared_future<int> sharedResult = divResult.share();
  std::cout << "3 divResult.valid() " << divResult.valid() << '\n';

  Requestor req;
  std::jthread sharedThread1(req, sharedResult);
  std::jthread sharedThread2(req, sharedResult);
  std::jthread sharedThread3(req, sharedResult);
  std::jthread sharedThread4(req, sharedResult);

  return 0;
}

