#include <iostream>
#include <iomanip>

#include <vector>

#include <memory>  // smart pointers: shared_ptr, unique_ptr, weak_ptr
#include <cassert> // assert

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  std::atomic<std::shared_ptr<std::string>> shareString (std::make_shared<std::string>("Zero"));

  std::thread t1([&shareString]{
	shareString.store(std::make_shared<std::string>(*shareString.load() + " One"));
  });

  std::thread t2([&shareString]{
	shareString.store(std::make_shared<std::string>(*shareString.load() + " Two"));
  });

  std::thread t3([&shareString]{
	shareString.store(std::make_shared<std::string>(*shareString.load() + " Three"));
  });

  std::thread t4([&shareString]{
	shareString.store(std::make_shared<std::string>(*shareString.load() + " Four"));
  });

  std::thread t5([&shareString]{
	shareString.store(std::make_shared<std::string>(*shareString.load() + " Five"));
  });

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  cout << *shareString.load() << '\n';

  // demo std::atomic<T*>
  int intArray[5];
  std::atomic<int*> p(intArray);
  p++;
  assert(p.load() == &intArray[1]);
  static_assert(&intArray[2] > &intArray[1], "pointer address error");

  p+=1;
  assert(p.load() == &intArray[2]);

  --p;
  assert(p.load() == &intArray[1]);
  return 0;
}

