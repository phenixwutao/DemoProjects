#include <atomic>
#include <thread>
#include <vector>
#include <random>
#include <memory>

#include <iostream>
using namespace std;

int main()
{
  // atomic operations for shared pointer are deprecated:
  std::atomic<std::shared_ptr<std::string>> shareString(std::make_shared<std::string>("zero"));

  // check if atomic shared_ptr lock free
  cout << "is_lock_free: " << shareString.is_lock_free() << endl;

  std::thread t1([&shareString]{
    shareString.store(std::make_shared<std::string>(*shareString.load() + "One"));
  });

  std::thread t2([&shareString]{
    shareString.store(std::make_shared<std::string>(*shareString.load() + "Two"));
  });

  std::thread t3([&shareString]{
    shareString.store(std::make_shared<std::string>(*shareString.load() + "Three"));
  });

  std::thread t4([&shareString]{
    shareString.store(std::make_shared<std::string>(*shareString.load() + "Four"));
  });

  std::thread t5([&shareString]{
    shareString.store(std::make_shared<std::string>(*shareString.load() + "Five"));
  });

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  cout << *shareString.load() << endl;
  return 0;
}

