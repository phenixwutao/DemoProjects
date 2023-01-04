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


  static std::once_flag initInstanceFlag;
  static MySingleton* instance;

  static void initSingleton()
  {
    instance = new MySingleton;
  }

public:
  static MySingleton* getInstance()
  {
    // Ensure initSingleton is called only once
    std::call_once(initInstanceFlag, initSingleton);
    return instance;
  }

  static void destroySingleton()
  {
    delete instance;
    instance = nullptr;
  }

};

MySingleton* MySingleton::instance = nullptr;
std::once_flag MySingleton::initInstanceFlag;

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::cout << "MySingleton::getInstance() " << MySingleton::getInstance() << '\n';
  std::cout << "MySingleton::getInstance() " << MySingleton::getInstance() << '\n';

  MySingleton::destroySingleton();
  return 0;
}

