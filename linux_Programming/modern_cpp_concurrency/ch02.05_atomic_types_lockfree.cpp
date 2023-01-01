#include <iostream>
#include <iomanip>

#include <vector>

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>

using namespace std;

std::vector<int> mySharedWork;
std::mutex mutex_;
std::condition_variable condVar;

bool dataReady {false};

void waitingForWork()
{
	std::cout << "waitingForWork Waiting ...\n";
	std::unique_lock<std::mutex> lck(mutex_);
	condVar.wait(lck, [](){ return dataReady; });
	mySharedWork[2] = 2;
	std::cout << "waitingForWork Work done\n";	
}


void setDataReady()
{
	mySharedWork = {1,0,3};
	{		
		std::unique_lock<std::mutex> lck(mutex_);
		dataReady = true;
	}
	std::cout << "setDataReady Data is prepared\n";
	condVar.notify_one();
}

int main(int argc, char *argv[])
{
  {
    std::cout << std::boolalpha;
    std::atomic<bool> flag1;
    cout <<flag1.is_lock_free() << '\n'; // template function

    bool flag2 = false;
    std::atomic_ref<bool> flag2_ref(flag2);
    cout << flag2_ref.is_always_lock_free << '\n'; // const expression
  }

  {
  	std::thread t1(waitingForWork);
  	std::thread t2(setDataReady);
  	t1.join();
  	t2.join();
  	for(auto i : mySharedWork)
  		cout << i << ' ';
  	cout << '\n';
  }
  return 0;
}

