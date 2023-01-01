#include <iostream>
#include <iomanip>

#include <vector>

#include <thread>
#include <utility>
#include <atomic>

#include <condition_variable>
#include <chrono>

using namespace std;

std::vector<int> mySharedWork;
std::atomic<bool> dataReady (false);


void waitingForWork()
{
	std::cout << "waitingForWork Waiting ...\n";
  while(!dataReady.load())
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
  }
	mySharedWork[2] = 2;
	std::cout << "waitingForWork Work done\n";	
}


void setDataReady()
{
	mySharedWork = {1,0,3};
  dataReady = true;
	std::cout << "setDataReady Data is prepared\n";
}

int main(int argc, char *argv[])
{
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

