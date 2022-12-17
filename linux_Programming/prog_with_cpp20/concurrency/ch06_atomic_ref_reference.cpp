#include <atomic>
#include <thread>
#include <vector>
#include <random>

#include <iostream>
using namespace std;

struct ExpensiveCopy {
  int counter {};
};

int getRandom(int begin, int end)
{
  std::random_device seed; // initial seed
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(begin, end);
  return uniformDist(engine);
}

void count(ExpensiveCopy& exp)
{
  vector<thread> v;
  std::atomic_ref<int> counter {exp.counter};
  for (int n = 0; n < 10; ++n)
    {
      v.emplace_back([&counter](){
	auto randomNumber = getRandom(100,200);
	for (int i = 0; i < randomNumber; ++i)
	  ++counter;
      });
    }

  for(auto& t : v)
    t.join();
}

int main()
{
  ExpensiveCopy exp;
  count(exp);
  cout << "exp.counter is: " << exp.counter << endl;

  cout << std::boolalpha; // check at compile time
  cout << "atomic_ref<type>::is_always_lock_free " <<
    atomic_ref<int>::is_always_lock_free << endl;
  return 0;
}



