#include <atomic>
#include <thread>
#include <vector>
#include <semaphore>
#include <memory>
#include <latch>
#include <barrier>

#include <iostream>
using namespace std;

// barrier enables some threads to block until a counter becomes zero.
std::barrier workDone(6);

std::mutex countMutex;

void synchronizedOut(const std::string& s)
{
  std::lock_guard<mutex> lo(countMutex);
  cout << s << endl;
}

class FullTimeWorker
{
public:
  FullTimeWorker (const string& n) : name(n) {}
  void operator()()
  {
    synchronizedOut(name + ": " + "Morning work done!\n");
    workDone.arrive_and_wait(); // Wait until morning work is done
    
    synchronizedOut(name + ": " + "Afternoon work done!\n");
    workDone.arrive_and_wait(); // Wait until afternoon work is done
  }
  
private:
  std::string name;
};


class PartTimeWorker
{
public:
  PartTimeWorker (const string& n) : name(n) {}
  void operator()()
  {
    synchronizedOut(name + ": " + "Morning work done!\n");
    workDone.arrive_and_drop(); // Wait until morning work is done
  }
  
private:
  std::string name;
};

int main()
{
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

