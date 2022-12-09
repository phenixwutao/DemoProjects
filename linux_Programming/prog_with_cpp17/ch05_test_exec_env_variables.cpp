#include <unistd.h>
#include <iostream>

int main()
{
  // pass arguments and env variables to child process
  const char* envp[] = {"ENV1=1", "ENV2=2", nullptr};
  execl("/bin/ls", "ls", nullptr, envp);
  printf("hello world\n");
  return 0;
}
