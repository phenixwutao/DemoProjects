#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int main(void)
{
  int id;
  auto id1 = fork();
  auto id2 = fork();
  auto id3 = fork();
  
  while(1)
    {
      id = wait(nullptr);
      if (id == -1)
	break;
      if (id == id1)
	std::cout << "child #1 finished\n";
      if (id == id2)
	std::cout << "child #2 finished\n";
      if (id == id3)
	std::cout << "child #3 finished\n";
    }
  if (id1 != 0 && id2 != 0 && id3 != 0)
    std::cout << "parent done\n";
  
  return 0;
}
