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

std::mutex coutMutex;

class Worker
{
  public:
    Worker(const std::string &n) : name(n){}

    void operator()()
    {
      for (int i = 1; i <= 3; ++i)
      {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        coutMutex.lock();
        cout << name << " : " << " Work " << i << " done! \n";
        coutMutex.unlock();
      }
    }

    private:
      string name;
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  cout << "Start working:\n";
  std::thread herb    = std::thread(Worker("Herb"));
  std::thread andrei  = std::thread(Worker("    Andrie"));
  std::thread scott   = std::thread(Worker("     Scott"));
  std::thread bjarne  = std::thread(Worker("       Bjarne"));
  std::thread bart    = std::thread(Worker("       Bart"));
  std::thread jenne   = std::thread(Worker("         Jenne"));
  herb.join();
  andrei.join();
  scott.join();
  bjarne.join();
  bart.join();
  jenne.join();
  cout << "End working:\n";
  return 0;
}

