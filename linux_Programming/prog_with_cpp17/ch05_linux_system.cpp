// page 143
#include <unistd.h>
#include <iostream>

int main()
{
  {
    auto wPID = fork(); // return child process ID
    printf("hello world\n");
    if (wPID != 0)
      printf("child process ID is %d\n", wPID);
    else
      printf("main process\n");
  }
    
  return 0;
}

