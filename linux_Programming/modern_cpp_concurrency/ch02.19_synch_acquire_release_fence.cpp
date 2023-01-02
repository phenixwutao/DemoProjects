#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

atomic<string*> ptr;
int intdata;
atomic<int> atomData;

void producer()
{
	string* p = new string("C++11");
	intdata = 2011;
	atomData.store(2014, std::memory_order_relaxed);

	atomic_thread_fence(std::memory_order_release); // protect store operation
	ptr.store(p, std::memory_order_release); // release operation
}

void consumer()
{
	string* p2;
	while( !(p2 = ptr.load(std::memory_order_acquire))); // acquire operation

	atomic_thread_fence(std::memory_order_acquire); // protect load operation
	cout << "*p2 = " << *p2 << '\n';
	cout << "intdata: " << intdata << '\n';
	cout << "atomData " << atomData.load(std::memory_order_relaxed) << '\n';
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  thread t1(producer);
  thread t2(consumer);
  t1.join();
  t2.join();

  delete ptr;

  return 0;
}

