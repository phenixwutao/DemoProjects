/***********************************************************
 * 1. types of system calls:
 * [1] console input/output: 
 *     C style printf, 
 *     CPP style cout, 
 *     Forking style stdout, stderr
 *     relay chars buffer parent process like shell
 * [2] memory allocation system call
 *     malloc, free
 * [3] file input/output
 * [4] Networking
 *     network-based system calls with POSIX socket
 * [5] time (date/time system call)
 * [6] thread and process creation
 *     shell => contains one or more processes
       a process is an execution unit
       a thread is running inside of a process sharing
       same resources for the same process, without IPC.
 ***********************************************************/
#include <stdlib.h>
#include <stdio.h> // printf
//#include <iostream>

int main()
{
  int* p1 = malloc(sizeof(int));
  *p1 = 1;
  printf("*p1= %d\n", *p1);
  free(p1);

  //int* p2 = new int;
  //delete p2;
  return 0;
}
