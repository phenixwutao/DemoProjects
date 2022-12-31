#include <iostream>
#include <thread>
#include <atomic>
#include <utility>

using namespace std;

class SpinLock
{
  std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
  void lock()
  {
    std::cout << std::boolalpha;

    // test_and_set: atomically changes the state of a std::atomic_flag to set (true)
    // and returns the value it held before.
    while(flag.test_and_set())
      {
	//std::cout << "lock: " << flag.test()<< '\n';
      }
  }

  void unlock()
  {
    flag.clear();
  }
};

SpinLock spin;

void workOnResource(int id)
{
  spin.lock();
  cout << "process shared resource: " << id << '\n';
  spin.unlock();
}

int main(int argc, char *argv[])
{
  {
    std::cout << std::boolalpha;
    cout << std::atomic<bool>{}.is_lock_free() << endl;
  }

  std::thread t1(workOnResource, 1);
  std::thread t2(workOnResource, 2);
  t1.join();
  t2.join();
  return 0;
}

