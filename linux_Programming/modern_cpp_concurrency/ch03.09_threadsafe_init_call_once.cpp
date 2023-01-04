#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::once_flag onceFlag;

void do_once1()
{
  std::call_once(onceFlag, [](){ std::cout << "only once 1\n"; });
}

void do_once2()
{
  std::call_once(onceFlag, [](){ std::cout << "only once 2"; });
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  // Exactly one execution of exactly one of the functions is performed. 
  // It is undefined which function is selected for execution.
  std::thread t1(do_once1); // register one callable unit 
  std::thread t2(do_once1);
  std::thread t3(do_once2);
  std::thread t4(do_once2);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  return 0;
}

