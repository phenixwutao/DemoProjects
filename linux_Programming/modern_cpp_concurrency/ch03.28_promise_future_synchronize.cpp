#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers
#include <exception>

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

void DoWork()
{
  std::cout << "process shared data, do work\n";
}

void waitingForWork(std::future<void>&& fut)
{
  std::cout << "Worker: waiting for the work:\n";
  fut.wait();
  DoWork();
  std::cout << "Work done\n";
}

void setDataReady(std::promise<void>&& prom)
{
  std::cout << "Sender: data is ready:\n";
  prom.set_value();
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  std::promise<void> sendReady;
  auto fut = sendReady.get_future();

  std::thread t1(waitingForWork, std::move(fut));
  std::thread t2(setDataReady, std::move(sendReady));
  t1.join();
  t2.join();
  return 0;
}

