#include <chrono>
#include <iostream>

#include <thread>
#include <condition_variable>
#include <atomic>

using namespace std;

std::atomic<int> counter {};
constexpr int countlimit = 100'000;

std::atomic<bool> atomicBool {};

void ping()
{
  while (counter <= countlimit)
    {
      atomicBool.wait(true); // wait if atomicBool is true, otherwise returns
      atomicBool.store(true);
      
      ++counter;
      
      atomicBool.notify_one();
    }
}

void pong()
{
  while (counter <= countlimit)
  {
    atomicBool.wait(false);
    atomicBool.store(false);
    atomicBool.notify_one();
  }
}

int main()
{
  std::cout << std::boolalpha;
  cout << "atomicBool.is_lock_free() " << atomicBool.is_lock_free() << '\n';
  
  auto start = std::chrono::system_clock::now();
  atomicBool.store(true);
  
  std::thread t1(ping);
  std::thread t2(pong);
  t1.join();
  t2.join();
  
  std::chrono::duration<double> dur =
    std::chrono::system_clock::now() - start;
  std::cout << "Duration: " << dur.count() << " seconds" << '\n';
  return 0;
}

