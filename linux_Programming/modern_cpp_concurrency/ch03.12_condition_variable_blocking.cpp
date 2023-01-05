#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::mutex mutex_;
std::condition_variable condVar;

void waitForWork()
{
  std::cout << "Worker: waiting for work.\n";
  std::unique_lock<std::mutex> lck(mutex_);
  condVar.wait(lck); // no predicate
  std::cout << "Work done\n";
}

void setDataReady()
{
  std::cout << "Sender: data is ready.\n";
  condVar.notify_one();
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  thread t2(setDataReady);
  thread t1(waitForWork);
  t1.join();
  t2.join();
  return 0;
}

