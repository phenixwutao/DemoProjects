#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

void mysystem(const char* command)
{
  if (auto id = fork(); id >0)
    {
      sleep(2);
      kill(id, SIGINT);
    }
  else
    {
      execlp(command, command, nullptr);
    }
}

int main()
{
  mysystem("pwd");
  return 0;
}
