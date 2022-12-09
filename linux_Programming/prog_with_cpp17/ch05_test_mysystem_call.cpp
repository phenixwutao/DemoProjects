#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

void mysystem(const char* command)
{
  if (fork() == 0) {
    execlp(command, command, nullptr);
  }
  else {
    wait(nullptr);
  }
}

int main()
{
  mysystem("ls");
  cout << "Hello World" << endl;
  return 0;
}
