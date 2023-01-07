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
  std::this_thread::sleep_for(100ms);
  for (int i = 0; i <= 9; ++i)
  {
    // register multiple callbacks using the same stop token, execution order is not guranteed:
    std::stop_callback cb(stoken, [i]
                          { std::cout << i << ' '; });
  }
  std::cout << '\n';
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::jthread t1(func);
  std::jthread t2(func);
  t1.request_stop();
  t2.request_stop();
  return 0;
}

