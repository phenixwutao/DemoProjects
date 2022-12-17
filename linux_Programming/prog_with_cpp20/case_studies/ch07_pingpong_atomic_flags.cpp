#include <chrono>
#include <iostream>

#include <thread>
#include <condition_variable>
#include <atomic>

using namespace std;

std::atomic<int> counter {};
constexpr int countlimit = 100'000;
bool dataReady = false;

std::mutex mut;
std::atomic_flag atomicFlag1 {};
std::atomic_flag atomicFlag2 {};

void ping()
{
  while (counter <= countlimit)
    {
      atomicFlag1.wait(false); // wait if atomicFlag1 is false, otherwise returns
      atomicFlag1.clear();
      ++counter;
      atomicFlag2.test_and_set();
      atomicFlag2.notify_one();
    }
}

void pong()
{
  while (counter <= countlimit)
  {
      atomicFlag2.wait(false);
      atomicFlag2.clear();
      
      atomicFlag1.test_and_set();
      atomicFlag1.notify_one();
  }
}

int main()
{
  auto start = std::chrono::system_clock::now();
  atomicFlag1.test_and_set();
  
  std::thread t1(ping);
  std::thread t2(pong);
  t1.join();
  t2.join();
  
  std::chrono::duration<double> dur =
    std::chrono::system_clock::now() - start;
  std::cout << "Duration: " << dur.count() << " seconds" << '\n';
  return 0;
}

