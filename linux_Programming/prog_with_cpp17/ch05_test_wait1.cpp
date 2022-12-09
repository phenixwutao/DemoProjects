#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int main()
{
  auto wPID = fork();
  if (wPID != 0)
    {
      wait(nullptr); // parent process waits here
      printf("parent\n");
    }
  else
    {
      printf("child\n");
    }
  return 0;
}
