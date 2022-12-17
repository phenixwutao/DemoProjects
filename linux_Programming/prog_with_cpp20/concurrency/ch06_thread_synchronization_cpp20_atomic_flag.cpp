#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include <future>
#include <atomic>

using namespace std;

std::vector<int> myvec;

//  std::atomic_flag automatic_flag = ATOMIC_FLAG_INIT; // C++11
std::atomic_flag atomicFlag {};

void prepareWork()
{
  myvec.insert(myvec.end(), {0,1,0,3});
  for(auto i : myvec)
    cout << i << ' ';
  cout << endl;

  cout << "Sender: data prepared:\n";

  // atomically sets the flag to true and obtains its previous value
  auto prev_flag = atomicFlag.test_and_set();
  printf("atomic prev_flag %s\n", prev_flag ? "true":"false");

  std::this_thread::sleep_for(3s);
  atomicFlag.notify_one();
}

void completeWork()
{
  cout << "Waiter: wait for the data\n";
  
  // the old value to check the atomic_flag's object no longer contains
  // stop waiting if previous flag is no longer false
  atomicFlag.wait(false);
  
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
