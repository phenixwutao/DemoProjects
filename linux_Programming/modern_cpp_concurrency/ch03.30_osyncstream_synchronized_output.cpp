#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers
#include <exception>

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>
#include <future>
#include <semaphore>
#include <latch>
#include <barrier>
#include <syncstream>

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

// std::osyncstream     std::basic_osyncstream<char>
// std::wosyncstream    std::basic_osyncstream<wchar_t>

class Worker
{
public:
  Worker(std::string n) : name(n){};
  void operator()()
  {
    for (int i = 1; i <= 3; ++i)
    {
      // begin work
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      // end work
      std::osyncstream syncStream(std::cout);
      syncStream << name << ": "
                << "Work " << i << " done !!!" << '\n';
    }
  }

private:
  std::string name;
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::cout << "Boss: Let's start working.\n\n";

  std::thread herb = std::thread(Worker("Herb"));
  std::thread andrei = std::thread(Worker(" Andrei"));
  std::thread scott = std::thread(Worker("  Scott"));
  std::thread bjarne = std::thread(Worker("   Bjarne"));
  std::thread bart = std::thread(Worker("   Bart"));
  std::thread jenne = std::thread(Worker("      Jenne"));

  herb.join();
  andrei.join();
  scott.join();
  bjarne.join();
  bart.join();
  jenne.join();

  std::cout << "\n"
            << "Boss: Let's go home." << '\n';
  return 0;
}

