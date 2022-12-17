#include <atomic>
#include <thread>
#include <vector>
#include <semaphore>
#include <memory>
#include <latch>

#include <iostream>
using namespace std;

std::latch workDone(6);
std::latch goHome(1);

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
    workDone.count_down();

    goHome.wait();
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

  workDone.wait();
  std::cout << "work all dones, wait:\n";
  std::this_thread::sleep_for(3s);

  std::cout << '\n';

  goHome.count_down();

  std::cout << "BOSS: GO HOME!" << '\n';

  herbWork.join();
  scottWork.join();
  bjarneWork.join();
  andreiWork.join();
  andrewWork.join();
  davidWork.join();
 
  return 0;
}

