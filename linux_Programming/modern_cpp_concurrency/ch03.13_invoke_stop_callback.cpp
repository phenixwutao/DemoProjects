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

auto func = [](std::stop_token stoken)
{
  int counter{0};
  auto thread_id = std::this_thread::get_id();
  std::stop_callback callBackFunc(stoken, [&counter, &thread_id]()
                                  { cout << "thread_id " << thread_id << " , counter " << counter << '\n'; });

  while(counter < 10)
  {
    std::this_thread::sleep_for(0.2s);
    ++counter;
  }
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  vector<std::jthread> vecThreads(10);
  for(auto& ithr : vecThreads)
  {
    ithr = std::jthread(func);
  }

  std::this_thread::sleep_for(1s);std::thread::id

  for(auto& ithr : vecThreads)
  {
    ithr.request_stop();
  }
  return 0;
}

