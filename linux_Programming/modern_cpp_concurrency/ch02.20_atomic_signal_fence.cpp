#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::atomic<bool> a {false};
std::atomic<bool> b {false};

extern "C" void handler(int)
{
  if (a.load(std::memory_order_relaxed))
  {
  	std::atomic_signal_fence(std::memory_order_acquire);
  	assert(b.load(std::memory_order_relaxed));
  }
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::signal(SIGTERM, handler); // setup termination signal with a handler

  b.store(true, std::memory_order_relaxed);
  std::atomic_signal_fence(std::memory_order_release);
  a.store(true, std::memory_order_relaxed);

  return 0;
}

