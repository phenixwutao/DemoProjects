#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

struct CriticalData
{
  std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b)
{
  a.mut.lock();
  std::cout << "get the first mutex\n";
  std::this_thread::sleep_for(1ms);
  b.mut.lock();
  std::cout << "get the second mutex\n";

  a.mut.unlock();
  b.mut.unlock();
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  CriticalData c1;
  CriticalData c2;
  std::thread t1([&]()
                 { deadLock(c1, c2); });

  std::thread t2([&]()
                 { deadLock(c2, c1); });

  t1.join();
  t2.join();
  return 0;
}

