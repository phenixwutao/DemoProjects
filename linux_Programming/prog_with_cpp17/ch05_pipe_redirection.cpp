#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <array>
#include <iostream>
#include <string_view>

using namespace std;

class MyPipe
{
  array<int,2> m_handles;

public:
  MyPipe(){
    if (pipe(m_handles.data()) < 0)
      exit(1);
  }

  ~MyPipe(){
    close(m_handles.at(0));
    close(m_handles.at(1));
  }

  std::string read()
  {
    std::array<char, 256> buf;
    std::size_t bytes = ::read(m_handles.at(0), buf.data(), buf.size());
    if (bytes > 0)
      return {buf.data(), buf.size()};
    else
      return {};
  }

  void redirect()
  {
    dup2(m_handles.at(1), STDOUT_FILENO);
    close(m_handles.at(0));
    close(m_handles.at(1));
  }
};

int main()
{
  MyPipe p;
  if (fork() == 0)
    {
      p.redirect();
      execlp("ls","ls",nullptr);
    }
  else
    {
      wait(nullptr);
      cout << p.read() << endl;
    }
  return 0;
}

