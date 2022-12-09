#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
  // child process because return value zero
  if (fork() == 0)
    {
      printf("Hello from Child!\n");
    }

  // parent process because return value non-zero.
  else
    {
      printf("Hello from Parent!\n");
    }
}

int main()
{
  /*
   * In the above code, a child process is created. fork() returns 0 in the child process and
   * positive integer in the parent process. Here, two outputs are possible because the parent process and
   * child process are running concurrently. So we don’t know whether the OS will first give control to
   * the parent process or the child process.
   */
  forkexample();
  
  return 0;
}

