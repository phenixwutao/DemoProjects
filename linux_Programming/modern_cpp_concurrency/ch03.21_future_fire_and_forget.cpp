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

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  // promises are executed in the sequence which you find in the source code. 
  // The execution sequence is independent of the execution time.
  std::async(std::launch::async, []()
             {
              std::this_thread::sleep_for(std::chrono::seconds(2));
              std::cout << "first thread" << '\n';
             });
  std::async(std::launch::async, []()
             {
              std::this_thread::sleep_for(std::chrono::seconds(1));
              std::cout << "second thread" << '\n';
             });
  std::cout << "main thread\n";
  return 0;
}

