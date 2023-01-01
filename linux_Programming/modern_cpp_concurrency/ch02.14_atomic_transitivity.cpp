#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

vector<int> mySharedWork;
std::atomic<bool> dataProduced(false);
std::atomic<bool> dataConsumed(false);

void dataProducer()
{
  mySharedWork = {1,0,3};
  dataProduced.store(true, std::memory_order_release); // release operation
}

void deliveryBoy()
{
  while(!dataProduced.load(std::memory_order_acquire)); // acquire operation
  dataConsumed.store(true, std::memory_order_release); 
}

void dataConsumer()
{
  while(!dataConsumed.load(std::memory_order_acquire));
  mySharedWork[1] = 2;
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::thread t1(dataConsumer);
  std::thread t2(deliveryBoy);
  std::thread t3(dataProducer);

  t1.join();
  t2.join();
  t3.join();

  for(auto i : mySharedWork) cout << i << ' ';
  cout << '\n';
  return 0;
}

