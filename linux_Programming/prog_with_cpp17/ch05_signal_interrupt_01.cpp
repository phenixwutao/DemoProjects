#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void handler(int sig)
{
  if (sig == SIGINT)
    {
      cout << "handler called : " << sig << endl; 
    }
}


int main()
{
  signal(SIGINT, handler); // setup a SIGINT signal handler function

  signal(SIGSTOP, handler); // setup stop signal handler
  for (int i = 0; i < 10; ++i)
    {
      cout << "hello running" << endl;
      sleep(1);
    }
  return 0;
}
