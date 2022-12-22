#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>
#include <map>

using namespace std;


// define alias via C++11 std
using index_t = int;
using NameValueList = std::vector<std::pair<int, std::string>>;
using fn_ptr = int(*)(int, char);

template <typename T>
struct foo
{
  using value_type = T;
};


template <typename T>
using customer_addresses_t = std::map<int, std::vector<T>>; // [1]

struct delivery_address_t {};

struct invoice_address_t {};

using customer_delivery_addresses_t = customer_addresses_t<delivery_address_t>; // [2]
using customer_invoice_addresses_t  = customer_addresses_t<invoice_address_t>;  // [3]


int main()
{
  return 0;
}
