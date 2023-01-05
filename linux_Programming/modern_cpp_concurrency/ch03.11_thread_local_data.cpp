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

std::mutex coutMutex;
thread_local std::string s("Hello from ");

void addThreadLocal(const string& s2)
{
  s += s2;
  std::lock_guard<mutex> guard(coutMutex);
  cout << "s\t" << s << '\n';
  cout << "&s\t" << &s << '\n';
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  thread t1(addThreadLocal, "t1");
  thread t2(addThreadLocal, "t2");
  thread t3(addThreadLocal, "t3");
  thread t4(addThreadLocal, "t4");

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  cout << "main s\t" << s << '\n';
  cout << "main &s\t" << &s << '\n';
  return 0;
}

