#include <chrono>
#include <iostream>

#include <thread>
#include <condition_variable>
#include <atomic>

using namespace std;

std::atomic<int> counter {};
constexpr int countlimit = 100'000;

std::counting_semaphore<1> signal2Ping(0);
std::counting_semaphore<1> signal2Pong(0);

void ping()
{
  while (counter <= countlimit)
    {
      signal2Ping.acquire();
      ++counter;
      signal2Pong.release();
    }
}

void pong()
{
  while (counter <= countlimit)
  {
    signal2Pong.acquire();
    signal2Ping.release();
  }
}

int main()
{
  
  auto start = std::chrono::system_clock::now();
  signal2Ping.release(); // increase the count by 1 as a start
  
  std::thread t1(ping);
  std::thread t2(pong);
  t1.join();
  t2.join();
  
  std::chrono::duration<double> dur =
    std::chrono::system_clock::now() - start;
  std::cout << "Duration: " << dur.count() << " seconds" << '\n';
  return 0;
}

