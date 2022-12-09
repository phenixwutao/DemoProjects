#include <unistd.h>
#include <iostream>

int main()
{
  const char* argv[] = {"ls", nullptr};
  execv("/bin/ls", const_cast<char**>(argv));
  printf("hello world\n");
  return 0;
}
