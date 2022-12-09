#include <iomanip>
#include <iostream>

template<std::size_t N>
class buf_t
{
private:
  char m_buf[N];

public:
  constexpr auto size() {return N;}
  constexpr auto data() {return m_buf;}
};

// overload extracter operator
template<std::size_t N>
std::istream& operator>>(std::istream& is, buf_t<N>& buf)
{
  is >> std::setw(buf.size()) >> buf.data();
  //std::cout << "check " << buf.data() << std::endl;
  return is;
}

int main()
{
  buf_t<2> bb;
  printf("please enter\n");
  std::cin >> bb;
  return 0;
}
