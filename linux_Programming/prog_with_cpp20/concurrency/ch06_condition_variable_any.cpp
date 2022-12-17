#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <condition_variable>

using namespace std;
using namespace std::literals;

std::mutex mut;
std::condition_variable_any condvar;

bool dataReady;

void receiver(std::stop_token stopToken)
{
  cout << "Waiting: \n";
  std::unique_lock<std::mutex> lck(mut);
  bool ret = condvar.wait(lck, stopToken, [](){return dataReady;});
  if (ret)
    cout << "Notification received:\n" << endl;
  else
    cout << "Stop request received:\n" << endl;
}

void sender()
{
  std::this_thread::sleep_for(5ms);
  {
    std::unique_lock<std::mutex> lck(mut);
    dataReady = true;
    cout << "Send notification\n";
  }
  condvar.notify_one();
}

int main()
{
  std::jthread t1(receiver);
  std::jthread t2(sender);
  t1.request_stop();

  std::cout << std::boolalpha;
  std::cout << "t1.joinable(): " << t1.joinable() << '\n';
  return 0;
}
