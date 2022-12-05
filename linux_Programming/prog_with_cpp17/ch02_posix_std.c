#include <stdio.h> // std io printf
#include <errno.h> // error handling with exception
#include <inttypes.h> // type information
#include <limits.h>   // limits of each data type

//#include <setjump.h>  // C style exception handling
#include <signal.h>   // handling signals
#include <stdbool.h>  // system types information
#include <stddef.h>   // std def information
#include <stdint.h>   // system types
#include <stdlib.h>   // various utilities, libs
#include <time.h>     // system time

int main()
{
  // example 1
  {
    int i[2] = {42, 43};
    int yy = 0;
    int* pyy = &yy;
    printf("*pyy= %d\n", *pyy);
    int *p = i;
    if (p) {
      // method #1
      printf("The answer is: %d and %d\n", i[0], p[0]);
      printf("The answer is: %d and %d\n", i[1], p[1]);
      
      // method #2
      printf("The answer is: %d and %d\n", *(i + 0), *(p + 0));
      printf("The answer is: %d and %d\n", *(i + 1), *(p + 1));
    }

  }
  return 0;
}

