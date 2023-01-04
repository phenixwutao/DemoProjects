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

class MySingleton
{
private:
  MySingleton() = default;
  ~MySingleton() = default;
  MySingleton(const MySingleton&) = delete;
  MySingleton& operator=(const MySingleton&) = delete;

public:
  static MySingleton& getInstance()
  {
    // With C++11, static variables with block scope have an additional guarantee;
    // they are initialized in a thread-safe way in current block scope
    static MySingleton s;
    return s;
  }
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::cout << "MySingleton::getInstance() " << &MySingleton::getInstance() << '\n';
  std::cout << "MySingleton::getInstance() " << &MySingleton::getInstance() << '\n';

  return 0;
}

