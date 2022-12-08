#include <unistd.h>
#include <iostream>

int main()
{
  //execl("/bin/ls", "ls", nullptr);
  system("ls");
  printf("hello world\n");
  return 0;
}
