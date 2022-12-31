#include <iostream>
#include <iomanip>

#include <vector>

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>
#include <chrono>

using namespace std;

std::vector<int> myvec;
std::atomic<bool> atomicBool {false};

void prepareWork()
{
  myvec.insert(myvec.end(), {0,1,0,3});
  cout << "sender: data prepared\n";
  atomicBool.store(true);
  atomicBool.notify_one();
}

void completeWork()
{
  cout << "waiter: waiting for the data\n";
  atomicBool.wait(false);
  myvec[2] = 2;
  cout <<"waiter: complete the work\n";

  for(auto i : myvec)
    cout << i << ' ';
  cout << '\n';
}


int main(int argc, char *argv[])
{
  {
  	std::thread t1(prepareWork);
  	std::thread t2(completeWork);
  	t1.join();
  	t2.join();
  }
  return 0;
}

