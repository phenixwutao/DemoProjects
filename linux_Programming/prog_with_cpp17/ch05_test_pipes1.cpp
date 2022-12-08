#include <string>
#include <unistd.h>
#include <sys/wait.h>

#include <array>
#include <iostream>
#include <string_view>

class mypipe
{
private:
  std::array<int,2> m_handles;

public:
  mypipe()
  {
    if (pipe(m_handles.data()) < 0 )
      {
	exit(1);
      }
  }
    
  ~mypipe()
  {
    close(m_handles.at(0));
    close(m_handles.at(1));
  }

  std::string read()
  {
    std::array<char, 256> buf;
    std::size_t bytes = ::read(m_handles.at(0), buf.data(), buf.size());
    if (bytes > 0 )
      {
	return {buf.data(), bytes};
      }
    return {};
  }

  void write(const std::string& msg)
  {
    ::write(m_handles.at(1), msg.data(), msg.size());
  }
    
};

int main()
{
  mypipe p;

  if (fork() != 0)
    {
      sleep(1);
      std::cout << "parent" << std::endl;
      p.write("done");
      wait(nullptr);
    }
  else
    {
      auto msg = p.read();
      std::cout << "child" << std::endl;
      std::cout << "catch msg in child: " << msg << std::endl;
    }
  
  return 0;
}

