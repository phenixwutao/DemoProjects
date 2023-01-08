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
#include <latch>
#include <barrier>

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

void getAnswer(std::promise<int> intPromise)
{
  std::this_thread::sleep_for(1s);
  intPromise.set_value(42);
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  std::promise<int> answerProm;
  auto fut = answerProm.get_future();

  std::thread prodThread(getAnswer, std::move(answerProm));

  // future status:
  // deferred => the function is not started
  // ready => the results is ready
  // timeout => the timeout has expired
  std::future_status status{};
  do {
    status = fut.wait_for(0.2s);
    std::cout << "continue wairing, do something else\n";
  } while (status != std::future_status::ready);
  cout << "answer is: " << fut.get() << '\n';

  prodThread.join();

  return 0;
}

