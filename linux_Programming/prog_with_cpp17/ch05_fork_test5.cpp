#include <unistd.h>
#include <iostream>

int main(void)
{
  auto id1 = fork();
  std::cout << "id1: " << id1 << '\n'; // output twice
  auto id2 = fork();
  std::cout << "id2: " << id2 << '\n'; // output 4 times
  std::cout << "-----------\n";
  // total output 6 times
}
