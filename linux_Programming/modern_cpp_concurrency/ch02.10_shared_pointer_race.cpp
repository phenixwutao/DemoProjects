#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::shared_ptr<int> ptr = std::make_shared<int>(2011);
  cout << "std::shared_ptr<int> ptr atomic_is_lock_free: " << std::atomic_is_lock_free(&ptr) << '\n';

  for (auto i = 0; i < 10; i++)
  {
  	  int value = 2014+i;
	  std::thread([&ptr, &value] {
	  	  ptr = std::make_shared<int>(value); // concurrent reading and writing of the underlying resource
	  	}).detach();
  }
  cout << *ptr << '\n'; // results is undefined
  return 0;
}

