#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include <future>

using namespace std;

std::vector<int> myvec;
void prepareWork( std::promise<void> prom)
{
  myvec.insert(myvec.end(), {0,1,0,3});
  for(auto i : myvec)
    cout << i << ' ';
  cout << endl;

  cout << "Sender: data prepared:\n";
  std::this_thread::sleep_for(3s);
  prom.set_value(); // set the value as sychronization
}

void completeWork(std::future<void> fut)
{
  cout << "Waiter: wait for the data\n";
  fut.wait(); // wait for the value to be set
  myvec[2] = 2;
  cout << "Waiter: complete the work\n";
  for(auto i : myvec)
    cout << i << ' ';
  cout << endl;
}

int main()
{
  std::promise<void> sendNotification;
  auto waitForNotification = sendNotification.get_future();
  thread t1(prepareWork, std::move(sendNotification));
  thread t2(completeWork, std::move(waitForNotification));
  t1.join();
  t2.join();
  
  return 0;
}
