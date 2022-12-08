// page 143
#include <unistd.h>
#include <iostream>

int data  = 0;
int main()
{
  {
    if (fork() != 0)
      {
	data = 4;
	printf("child data is %d\n", data);
      }
    else
      printf("main data is %d\n", data);
  }
    
  return 0;
}

