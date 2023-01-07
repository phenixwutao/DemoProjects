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

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::vector<int> myvec;
std::counting_semaphore<1> prepareSignal(0); // max count 1, init as 0

void prepareWork()
{
  myvec.insert(myvec.end(), {0,1,0,3});
  std::cout << "Send : data prepared\n";
  std::this_thread::sleep_for(2s);
  prepareSignal.release(); // count plus 1
}

void completeWork()
{
  for (int i = 0; i < 5; ++i)
  {
    std::cout << "Waiter: waiting for data\n";
    std::this_thread::sleep_for(400ms);
  }
  prepareSignal.acquire(); // Decrements the counter by 1 or blocks until the counter is > 0
  myvec[2] = 2;
  std::cout << "Waiter: complete the work\n";
  for (auto i : myvec)
    cout << i << ' ';
  cout << '\n';
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  thread t2(completeWork);
  thread t1(prepareWork);
  t1.join();
  t2.join();
  return 0;
}

