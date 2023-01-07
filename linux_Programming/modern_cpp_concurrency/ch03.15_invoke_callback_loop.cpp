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

#include <chrono>
#include <functional>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

using handler_t  = std::function<void()>;
using callback_t = std::stop_callback<handler_t>;

void func(std::stop_token stopToken)
{
  // callbacks registered before stop request
  std::list<callback_t> callbacks;
  for (int i = 0; i <= 9; ++i)
  {
    callbacks.emplace_back(stopToken, [i]
                           { std::cout << i << ' '; });
  }
  std::this_thread::sleep_for(100ms);
  cout << '\n';
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  jthread t1(func);
  jthread t2(func);
  std::this_thread::sleep_for(50ms);
  t1.request_stop();
  t2.request_stop();
  return 0;
}

