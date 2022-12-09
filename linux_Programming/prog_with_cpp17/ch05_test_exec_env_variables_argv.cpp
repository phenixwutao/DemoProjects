#include <unistd.h>
#include <iostream>

int main()
{
  // pass arguments and env variables to child process
  const char* argv[] = {"ls", nullptr};
  const char* envp[] = {"ENV1=1", "ENV2=2", nullptr};

  execve("/bin/ls",
	 const_cast<char**>(argv),
	 const_cast<char**>(envp));
  
  printf("hello world\n");
  return 0;
}
