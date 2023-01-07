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

void OnCompletion()
{
  cout << "All completed\n";
}
std::barrier workDone(6, OnCompletion);
std::mutex countMut;

void sychronizedOut(const string& s)
{
  std::lock_guard<mutex> lock(countMut);
  std::cout << s;
}

class FullTimeWorker
{
public:
  FullTimeWorker(std::string n) : name(n) {}

  void operator()()
  {
    sychronizedOut(name + " : Morning work done\n");
    // Equivalent to arrive and wait, when counter > 0 , then wait status
    workDone.arrive_and_wait();
    sychronizedOut(name + " : Afternoon work done\n");
    workDone.arrive_and_wait();
  }

private:
  std::string name;
};

class PartTimeWorker
{
public:
  PartTimeWorker(std::string n) : name(n) {}

  void operator()()
  {
    sychronizedOut(name + " : Morning work done\n");
    // Decrements the counter for the current and the subsequent phase by one
    workDone.arrive_and_drop();
  }

private:
  std::string name;
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  FullTimeWorker herb(" Herb");
  std::thread herbWork(herb);

  FullTimeWorker scott(" Scott");
  std::thread scottWork(scott);

  FullTimeWorker bjarne(" Bjarne");
  std::thread bjarneWork(bjarne);

  PartTimeWorker andrei(" Andrei");
  std::thread andreiWork(andrei);

  PartTimeWorker andrew(" Andrew");
  std::thread andrewWork(andrew);

  PartTimeWorker david(" David");
  std::thread davidWork(david);

  herbWork.join();
  scottWork.join();
  bjarneWork.join();
  andreiWork.join();
  andrewWork.join();
  davidWork.join();
  return 0;
}
