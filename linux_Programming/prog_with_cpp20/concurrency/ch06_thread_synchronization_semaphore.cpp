#include <atomic>
#include <thread>
#include <vector>
#include <semaphore>
#include <memory>

#include <iostream>
using namespace std;

std::vector<int> myvec;

std::counting_semaphore<1> prepareSignal(0); // initialised as 0, max value is 1

void prepareWork()
{
  myvec.insert(myvec.end(), {0,1,0,3});
  for(auto i : myvec)
    cout << i << ' ';
  cout << endl;

  cout << "Sender: data prepared:\n";
  prepareSignal.release(); // semaphore is increased by 1
}

void completeWork()
{
  cout << "Waiter: wait for the data\n";

  prepareSignal.acquire(); // semaphore is decreased by 1, if zero then blocked

  myvec[2] = 2;
  cout << "Waiter: complete the work\n";
  for(auto i : myvec)
    cout << i << ' ';
  cout << endl;
}

int main()
{
  std::thread t1(prepareWork);
  std::thread t2(completeWork);
  t1.join();
  t2.join();
  return 0;
}

