#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <memory> // smart pointers
#include <exception>

#include <execution> // parallel execution policy

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>
#include <future>
#include <semaphore>
#include <latch>
#include <barrier>

#include <chrono>
#include <functional> // std::function<>

#include <cassert>
#include <csignal>

#include <condition_variable>

#include <algorithm>
#include <numeric>

using namespace std;
using namespace std::chrono_literals;

template <typename T>
class MessageQueue
{
public:
void push(const T& item)
{
  std::lock_guard<mutex> lock(_mutex);
  _messageQueue.push(item);
  _condvar.notify_one();
}

T pop()
{
  std::unique_lock<mutex> lock(_mutex);
  _condvar.wait(lock, !_messageQueue.empty());
  T item = _messageQueue.front();
  _messageQueue.pop();
  return std::move(item);
}

void pop(T& item)
{
  std::unique_lock<mutex> lock(_mutex);
  _condvar.wait(lock, [this](){ return !_messageQueue.empty(); });
  item = _messageQueue.front();
  _messageQueue.pop();
}

private:
  std::queue<T> _messageQueue;  // use queue container
  std::mutex _mutex;
  std::condition_variable _condvar;
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  MessageQueue<std::string> myqueue;
  myqueue.push("hello");
  myqueue.push("world");
  std::string mess;
  myqueue.pop(mess);
  cout << mess << '\n';

  myqueue.pop(mess);
  cout << mess << '\n';

  return 0;
}

