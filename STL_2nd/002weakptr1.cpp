#include <iostream>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

using namespace std;

int main()
{
  try {
    shared_ptr<string> sp(new string("hi")); // create shared pointer
    weak_ptr<string> wp = sp; // create weak pointer out of it, weak ptr do not count into object
    sp.reset(); // release object of shared pointer
    cout << wp.use_count() << endl; // prints: 0
    cout << boolalpha << wp.expired() << endl; // prints: true
    shared_ptr<string> p(wp); // throws std::bad_weak_ptr because weak ptr is empty now
  }
  catch (const std::exception& e) {
    cerr << "exception: " << e.what() << endl; // prints: bad_weak_ptr
  }

  auto del = [] (int* p) {
    delete p;
  };
  std::shared_ptr<int> p(new int, del);
  decltype(del)* pd = std::get_deleter<decltype(del)>(p);

 return 0;  
}


