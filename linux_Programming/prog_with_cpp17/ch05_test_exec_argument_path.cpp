#include <unistd.h>
#include <iostream>

int main()
{
  const char* argv[] = {"ls", nullptr};
  
  execvp("ls", const_cast<char**>(argv));
  
  printf("hello world\n");
  return 0;
}
