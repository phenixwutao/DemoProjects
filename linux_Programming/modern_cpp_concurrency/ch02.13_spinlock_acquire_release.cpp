#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

class SpinLock {
private:
  std::atomic_flag flag;

public:
  SpinLock() : flag (ATOMIC_FLAG_INIT) {}

  void lock()
  {
    while(flag.test_and_set(std::memory_order_acquire)); // acquire operation
  }

  void unlock()
  {
    flag.clear(std::memory_order_release); // release ooperation
  }
};


SpinLock spin;

void WorkOnResource(int id)
{
  spin.lock();
  cout << "shared resource " << id << '\n';
  spin.unlock();
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  std::thread t1 (WorkOnResource, 1);
  std::thread t2 (WorkOnResource, 2);
  t1.join();
  t2.join();
  return 0;
}

