#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
  int x = 1;

  if (fork() == 0)
    printf("Child has x = %d\n", ++x);
  else
    printf("Parent has x = %d\n", --x);
}

int main()
{
  forkexample();
  /* possible output:
  * Parent has x = 0
  * Child has x = 2
  * The global variable change in one process does not affected two other processes because
  * data/state of two processes are different. And also parent and child run simultaneously
  * so two outputs are possible.
  */
  return 0;
}

