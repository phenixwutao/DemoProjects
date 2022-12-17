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
std::condition_variable condVar1;
std::condition_variable condVar2;

void ping()
{
  while (counter <= countlimit)
  {
    {
      std::unique_lock<std::mutex> lck(mut);
      condVar1.wait(lck, [](){
	return dataReady == false;
      });
      dataReady = true;
    }
  ++counter;
  condVar2.notify_one();
  }
}

void pong()
{
  while (counter <= countlimit)
  {
    {
      std::unique_lock<std::mutex> lck(mut);
      condVar2.wait(lck, []{
	return dataReady == true;
      });
      dataReady = false;
    }
    condVar1.notify_one();
  }
}

int main()
{
  auto start = std::chrono::system_clock::now();
  std::thread t1(ping);
  std::thread t2(pong);
  t1.join();
  t2.join();
  std::chrono::duration<double> dur =
    std::chrono::system_clock::now() - start;
  std::cout << "Duration: " << dur.count() << " seconds" << '\n';
  return 0;
}

