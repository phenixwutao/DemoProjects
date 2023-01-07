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

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;


// std::latch helps to manage one task by multiple threads.
std::latch workDone(6);
std::latch goHome(1);
std::mutex countMut;

void synchronizedOut(const string& str)
{
  std::lock_guard<mutex> lock(countMut);
  std::cout << str;
}

class Worker {
  public:
    Worker(std::string n) : name(n)
    {}

    void operator()()
    {
      synchronizedOut(name + " : Work done\n");
      workDone.count_down();
      goHome.wait();
      synchronizedOut(name + " : Goodbye\n");
    }

  private:
    std::string name;
};

int main(int argc, char *argv[])
{
    std::cout << std::boolalpha;
    std::cout << "Boss : Start working\n";
    Worker herb(" Herb");
    std::thread herbWork(herb);
    Worker scott(" Scott");
    std::thread scottWork(scott);

    Worker bjarne(" Bjarne");
    std::thread bjarneWork(bjarne);

    Worker andrei(" Andrei");
    std::thread andreiWork(andrei);

    Worker andrew(" Andrew");
    std::thread andrewWork(andrew);

    Worker david(" David");
    std::thread davidWork(david);

    // blocks until counter == 0.
    workDone.wait(); // main thread is blocked and waiting here

    std::cout << '\n';

    goHome.count_down(); // signal workers to go home

    std::cout << "BOSS: GO HOME!" << '\n';

    herbWork.join();
    scottWork.join();
    bjarneWork.join();
    andreiWork.join();
    andrewWork.join();
    davidWork.join();
    return 0;
}
