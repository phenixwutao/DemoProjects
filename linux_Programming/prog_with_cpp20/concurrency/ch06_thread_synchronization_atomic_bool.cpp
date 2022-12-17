#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include <future>
#include <atomic>

using namespace std;

std::vector<int> myvec;

std::atomic<bool> atomicBool {false};

void prepareWork()
{
  myvec.insert(myvec.end(), {0,1,0,3});
  for(auto i : myvec)
    cout << i << ' ';
  cout << endl;

  cout << "Sender: data prepared:\n";

  atomicBool.store(true);
  std::this_thread::sleep_for(3s);
  atomicBool.notify_one();
}

void completeWork()
{
  cout << "Waiter: wait for the data\n";
  
  atomicBool.wait(false);
  
  myvec[2] = 2;
  cout << "Waiter: complete the work\n";
  for(auto i : myvec)
    cout << i << ' ';
  cout << endl;
}

int main()
{
  thread t1(prepareWork);
  thread t2(completeWork);
  t1.join();
  t2.join();
  
  return 0;
}
