#include <chrono>
#include <iostream>
#include <thread>
#include <syncstream> // synchronized stream std::basic_osyncstream

using namespace std;

class Worker
{
public:
  Worker(const std::string& n) : name (n) {}
  void operator()()
  {
    for(unsigned short i=1; i<=3; ++i)
      {
	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	std::osyncstream synchstream(std::cout);
	synchstream << name << ": Work " << i << " done!!!" << '\n';
      }
  }
private:
  std::string name;
};

int main()
{
  std::cout << "Boss: Let's start working.\n\n";

  std::thread herb= std::thread(Worker("1 Herb"));
  std::thread andrei= std::thread(Worker("2 Andrei"));
  std::thread scott= std::thread(Worker("3 Scott"));
  std::thread bjarne= std::thread(Worker("4 Bjarne"));
  std::thread bart= std::thread(Worker("5 Bart"));
  std::thread jenne= std::thread(Worker("6 Jenne"));


  herb.join();
  andrei.join();
  scott.join();
  bjarne.join();
  bart.join();
  jenne.join();

  std::cout << "\n" << "Boss: Let's go home." << '\n';
  return 0;
}
