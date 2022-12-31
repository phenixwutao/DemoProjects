#include <iostream>
#include <iomanip>

#include <vector>

#include <thread>
#include <utility>
#include <atomic>

using namespace std;

vector<int> myvec;

std::atomic_flag atomicFlag {};

void prepareWork()
{
  myvec.insert(myvec.end(), {0,1,0,3});
  std::cout << "sender: data prepared" << '\n';
  atomicFlag.test_and_set();
  atomicFlag.notify_one();
}

void completeWork()
{
  cout << "waiter: waiting for data.\n";
  
  // if flag is false, then block and wait. If true, then unblock
  atomicFlag.wait(false);

  myvec[2] = 2; // modify the data
  cout << "waiter: complete the work\n";
  for (auto i : myvec) std::cout << i << '\n';
  cout << '\n';
}

int main(int argc, char *argv[])
{
  thread t1(prepareWork);
  thread t2(completeWork);
  t1.join();
  t2.join();
  return 0;
}

