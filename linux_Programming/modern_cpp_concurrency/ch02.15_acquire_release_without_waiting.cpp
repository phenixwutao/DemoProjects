#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

std::vector<int> mySharedWork;
std::atomic<bool> dataProduced (false);

void dataProducer()
{
  mySharedWork = {1,0,3};
  dataProduced.store(true, std::memory_order_release);
}

void dataConsumer()
{
  // while ( ! dataProduced.load(std::memory_order_acquire));
  dataProduced.load(std::memory_order_acquire); // cause Segmentation fault
  mySharedWork[1] = 2;
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  thread t1(dataConsumer);
  thread t2(dataProducer);
  t1.join();
  t2.join();

  for(auto i : mySharedWork)
    cout << i << ' ';
  cout << '\n';
  
  return 0;
}

