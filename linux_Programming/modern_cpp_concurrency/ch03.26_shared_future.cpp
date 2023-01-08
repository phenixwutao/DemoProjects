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

std::mutex coutMutex;

struct Div{
  void operator()(std::promise<int>&& intPromise, int a, int b)
  {
    intPromise.set_value(a/b);
  }
};

struct Requestor{
  void operator()(std::shared_future<int> shaFuture)
  {
    std::lock_guard<mutex> lock(coutMutex);
    std::cout << "thread id(" << std::this_thread::get_id() << "): ";
    std::cout << "20/10= " << shaFuture.get() << '\n';
  }
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::promise<int> divPromise;
  std::shared_future<int> divResult = divPromise.get_future();

  Div div;
  std::thread divThread(div, std::move(divPromise), 20, 10);

  Requestor req;
  // std::future object that can only be moved, std::shared_future object can ne copied
  std::thread sharedThread1(req, divResult);
  std::thread sharedThread2(req, divResult);
  std::thread sharedThread3(req, divResult);
  std::thread sharedThread4(req, divResult);

  divThread.join();
  sharedThread1.join();
  sharedThread2.join();
  sharedThread3.join();
  sharedThread4.join();
  return 0;
}

