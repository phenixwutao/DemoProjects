#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers
#include <cassert> // assert

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

// atomic method: compare_exchange_strong
// bool compare_exchange_strong( T& expected, T desired)
// if current contained value is the same as expected, then replace it by desired value,
// otherwise replaces expected value by the contained value.

template<typename T>
T fetch_multiply(std::atomic<T>& shared, T mult)
{
	T oldvalue = shared.load();
	while(shared.compare_exchange_strong(oldvalue, oldvalue* mult));
	return oldvalue;
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  std::atomic<int> myInt {5};
  cout << myInt << '\n';
  fetch_multiply(myInt, 5);
  cout << myInt << '\n';

  std::atomic<int> a1{3};
  cout << "atomic_signed_lock_free " << a1.is_lock_free() << '\n';

  std::atomic<unsigned int> a2{3};
  cout << "atomic_unsigned_lock_free " << a2.is_lock_free() << '\n';

  // Implicit conversion to the underlying type
  std::atomic<long long> atomObj(2011);
  atomObj = 2014;
  long long nonAtomObj = atomObj;
  return 0;
}

