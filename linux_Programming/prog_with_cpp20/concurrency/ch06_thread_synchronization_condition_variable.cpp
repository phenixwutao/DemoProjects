#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

std::mutex mut;
std::condition_variable condVar;
std::vector<int> myvec;

void prepareWork()
{
  {
    std::lock_guard<mutex> lck(mut);
    myvec.insert(myvec.end(), {0,1,0,3});
  }
  cout << "sender data prepared\n";
  condVar.notify_one();
}

void completeWork()
{
  cout << "Waiter: wait for the data: \n";
  std::unique_lock<std::mutex> lck(mut);
  condVar.wait(lck, []() {    // predicate function: is predicate is true, then wake up
    return not myvec.empty(); // also works for predicate !myvec.empty()
    });
  myvec[2] = 2;
  cout << "Waiter: complete the work" << endl;
  for(auto i : myvec)
    cout << i << ' ';
  cout << '\n';
}

int main()
{
  thread t1(prepareWork);
  thread t2(completeWork);
  t1.join();
  t2.join();
  return 0;
}
