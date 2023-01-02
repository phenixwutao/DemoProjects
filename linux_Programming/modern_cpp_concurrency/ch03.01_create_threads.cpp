#include <iostream>
#include <iomanip>
#include <string>

#include <vector>

#include <memory> // smart pointers

#include <thread>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

void helloFunction()
{
  std::cout << "hello from a function\n";
}

class HelloFunctionObject
{
  public:
  	void operator()() const
  	{
  	  cout << "Hello from a function object\n";
  	}
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  thread t1(helloFunction);

  HelloFunctionObject funcObj;
  thread t2(funcObj);

  thread t3( [](){
  		cout << "hello from lambda ID: " << this_thread::get_id() << '\n';
  	} );

  t1.join();
  t2.join();
  t3.join();

  return 0;
}

