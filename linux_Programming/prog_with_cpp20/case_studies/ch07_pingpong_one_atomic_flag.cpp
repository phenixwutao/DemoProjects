#include <chrono>
#include <iostream>

#include <thread>
#include <condition_variable>
#include <atomic>

using namespace std;

std::atomic<int> counter {};
constexpr int countlimit = 100'000;

std::atomic_flag atomicFlag {};

void ping()
{
  while (counter <= countlimit)
    {
      atomicFlag.wait(true); // wait if atomicFlag is true, otherwise returns
      atomicFlag.test_and_set();
      
      ++counter;
      
      atomicFlag.notify_one();
    }
}

void pong()
{
  while (counter <= countlimit)
  {
    atomicFlag.wait(false);
    atomicFlag.clear();
    atomicFlag.notify_one();
  }
}

int main()
{
  auto start = std::chrono::system_clock::now();
  atomicFlag.test_and_set();
  
  std::thread t1(ping);
  std::thread t2(pong);
  t1.join();
  t2.join();
  
  std::chrono::duration<double> dur =
    std::chrono::system_clock::now() - start;
  std::cout << "Duration: " << dur.count() << " seconds" << '\n';
  return 0;
}

