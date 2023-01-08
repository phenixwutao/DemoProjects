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

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  auto begin = std::chrono::system_clock::now();

  auto asyncLazy = std::async(std::launch::deferred, []()
                             { return std::chrono::system_clock::now(); });

  auto asyncEager = std::async(std::launch::async, []()
                               { return std::chrono::system_clock::now(); });

  std::this_thread::sleep_for(1s);

  auto lazyStart = asyncLazy.get() - begin;
  auto eagerStart = asyncEager.get() - begin;
  auto lazyDuration = std::chrono::duration<double>(lazyStart).count();
  auto eagerDuration = std::chrono::duration<double>(eagerStart).count();
  cout << "async Lazy evaluated after: " << lazyDuration << " seconds\n";
  cout << "async Eager evaluated after: " << eagerDuration << " seconds\n";
  return 0;
}

