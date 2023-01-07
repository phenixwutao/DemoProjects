#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>
#include <future>

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::mutex mut;
std::condition_variable_any condVar;
bool fDataReady;

void receiver(std::stop_token stopToken)
{
  cout << "waiting\n";

  std::unique_lock<std::mutex> lock(mut);
  bool fReturn = condVar.wait(lock, stopToken, []()
                              { return fDataReady; });
  if (fReturn == true)
    cout << "Notofication is received from cond variable\n";
  else
    cout << "Stop request is recived\n";
}

void sender()
{
  std::this_thread::sleep_for(5ms);
  {
    std::lock_guard<std::mutex> lock(mut);
    fDataReady = true;
    cout << "Send notification\n";
  }
  condVar.notify_one();
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::jthread t1(receiver);
  std::jthread t2(sender);

  t1.request_stop(); // stop request is sent before condVar notification

  t1.join();
  t2.join();
  return 0;
}

