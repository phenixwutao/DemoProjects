#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <list>
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


class RWLock {
private:
  std::mutex mutex;
  std::condition_variable condReaders;
  std::condition_variable condWriters;
  int readers = 0;
  int queuedWriters = 0;
  bool writer = false;

public:
  void readLock() {
    std::unique_lock<std::mutex> lock(mutex);
    condReaders.wait(lock, [this]{return !writer && queuedWriters == 0;});
    ++readers;
  }

  void readUnlock() {
    std::unique_lock<std::mutex> lock(mutex);
    --readers;
    if (readers == 0 && queuedWriters > 0) {
      lock.unlock();
      condWriters.notify_one();
    }
  }

  void writeLock() {
    std::unique_lock<std::mutex> lock(mutex);
    ++queuedWriters;
    condWriters.wait(lock, [this]{return !writer && readers == 0;});
    --queuedWriters;
    writer = true;
  }

  void writeUnlock() {
    std::unique_lock<std::mutex> lock(mutex);
    if(queuedWriters > 0) {
      lock.unlock();
      condWriters.notify_one();
    } else {
      writer = false;
      lock.unlock();
      condReaders.notify_all(); // unlock the writer, now can start read
      }
    }
};


int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  return 0;
}

