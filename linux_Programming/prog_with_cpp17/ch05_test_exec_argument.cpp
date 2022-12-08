#include <unistd.h>
#include <iostream>

int main()
{
  // pass arguments to child process
  execl("/bin/ls", "ls", "-al", nullptr);
  printf("hello world\n");
  return 0;
}
