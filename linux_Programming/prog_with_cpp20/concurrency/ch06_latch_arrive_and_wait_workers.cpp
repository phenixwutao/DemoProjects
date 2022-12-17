#include <atomic>
#include <thread>
#include <vector>
#include <semaphore>
#include <memory>
#include <latch>

#include <iostream>
using namespace std;

std::latch workDone(6);

std::mutex countMutex;

void synchronizedOut(const std::string& s)
{
  std::lock_guard<mutex> lo(countMutex);
  cout << s << endl;
}

class Worker
{
public:
  Worker(const std::string& n) : name(n) {}

  void operator()()
  {
    synchronizedOut(name + ": Work done!\n");

    // latch blocks until counter is zero
    workDone.arrive_and_wait(); // calls count_down(upd); wait();

    synchronizedOut(name + ": Good bye!\n");    
  }
    
private:
  std::string name;
};

int main()
{
  std::cout << "BOSS: START WORKING! " << '\n';

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

  herbWork.join();
  scottWork.join();
  bjarneWork.join();
  andreiWork.join();
  andrewWork.join();
  davidWork.join();
 
  return 0;
}

