#include <iostream>
#include <iomanip>

#include <vector>

#include <memory> // smart pointers
#include <random> // random numbers

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

struct ExpensiveToCopy{
	int counter {};
};

int getRandom(int begin, int end)
{
	std::random_device seed;  // initial seed
	std::mt19937 engine(seed()); // generator
	std::uniform_int_distribution<> uniformDist(begin, end);
	return uniformDist(engine);
}

void count(ExpensiveToCopy& exp)
{
	std::vector<std::thread> v;
	std::atomic<int> counter {exp.counter}; // atomic copy
	// std::atomic_ref<int> counter {exp.counter}; // atomic reference
	for(int n=0; n < 10; ++n)
	{
		v.emplace_back([&counter](){
			auto randomNumber = getRandom(100,200);
			for (int i =0; i < randomNumber; ++i)
			{
				++counter;
			}
		});
	}
	for(auto& t : v) t.join();
}


void atomicRefCopy()
{
	int val{5};
	int& ref = val;
	std::atomic<int> atomicRef(ref);
	++atomicRef;
	std::cout << "ref: " << ref << '\n';
	std::cout << "atomicRef.load(): " << atomicRef.load() << '\n';	
}

struct Point {
	int x;
	int y;
};

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;

  ExpensiveToCopy exp;
  count(exp);
  std::cout << "exp.counter " << exp.counter << '\n';

  atomicRefCopy();

  Point p {1,2};
  std::atomic_ref<Point> pref(p);

  return 0;
}

