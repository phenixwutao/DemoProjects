#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#include <iostream>

using namespace std;


char* get_shared_memory()
{
  auto key = ftok("myfile", 42); // generate a key by linux OS
  // open the shared memory
  // 0x1000 size is 4 KB
  // 0666 | IPC_CREAT open shared memory wit read+write permissions
  auto shm = shmget(key, 0x1000, 0666 | IPC_CREAT);

  // shm is the shared memory handle, to be used by shmat to return the pointer of shared mem
  return static_cast<char*>(shmat(shm, nullptr, 0));
}

int main()
{
  if (fork() != 0)
    {
      sleep(3);
      cout << "parent" << endl;

      auto msg = get_shared_memory();
      msg[0] = 42;
      wait(nullptr);
    }
  else
    {
      auto msg = get_shared_memory();
      while (msg[0] != 42)
	{
	  //printf("child waiting\n");
	}
      
      cout << "child" << endl;
    }
  
  return 0;
}
