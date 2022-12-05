#include <iostream>
#include <limits>

#include <typeinfo> // type information
#include <string>
#include <cstdint>
#include <cxxabi.h> // demangle type information

using namespace std;


template<typename T>
std::string type_name()
{
  int status = 0;
  std::string name = typeid(T).name();
  auto demangle_name =
    abi::__cxa_demangle(name.c_str(), nullptr, nullptr, &status);
  if (status == 0)
    {
      name = demangle_name;
      std::free(demangle_name);
    }
  return name;
}

static unsigned short wcount = 0;

template<typename T1, typename T2>
void are_equal()
{
  printf("------> start comparison ------ wcount %u\n", ++wcount);
#define red "\033[1;31m"
#define reset "\033[0m"
  std::cout << type_name<T1>() << " vs "
	    << type_name<T2>() << '\n';
  if (sizeof(T1) == sizeof(T2))
    {
      std::cout << " - size: both == " << sizeof(T1) << '\n';
    }
  else {
    std::cout << red " - size: "
	      << sizeof(T1)
	      << " != "
	      << sizeof(T2)
	      << reset "\n";
  }
  
  if (type_name<T1>() == type_name<T2>()) {
    std::cout << " - name: both == " << type_name<T1>() << '\n';
  }
  else {
    std::cout << red " - name: "
	      << type_name<T1>()
	      << " != "
	      << type_name<T2>()
	      << reset "\n";
  }
}


int main()
{
  // code snippet 1
  {
    char c = 0x42;
    cout << c << endl;
    int i = 0x42;
    cout << i << endl;

    const char* str= "Hello world!\n";
    cout << str ;
  }

  // code snippet 2
  {
    printf("char limits\n");
    auto num_bytes_signed = sizeof(signed char);
    auto min_signed = std::numeric_limits<signed char>().min();
    auto max_signed = std::numeric_limits<signed char>().max();

    auto num_bytes_unsigned = sizeof(unsigned char);
    auto min_unsigned = std::numeric_limits<unsigned char>().min();
    auto max_unsigned = std::numeric_limits<unsigned char>().max();

    std::cout << "num bytes (signed): " << num_bytes_signed << '\n';
    std::cout << "min value (signed): " << +min_signed << '\n';
    std::cout << "max value (signed): " << +max_signed << '\n';

    std::cout << '\n';

    std::cout << "num bytes (unsigned): " << num_bytes_unsigned << '\n';
    std::cout << "min value (unsigned): " << +min_unsigned << '\n';
    std::cout << "max value (unsigned): " << +max_unsigned << '\n';
  }

  // code snippet 3
  {
    printf("wchar_t limits\n");
    auto num_bytes_signed = sizeof(wchar_t);
    auto min_signed = std::numeric_limits<wchar_t>().min();
    auto max_signed = std::numeric_limits<wchar_t>().max();
    auto num_bytes_unsigned = sizeof(wchar_t);
    auto min_unsigned = std::numeric_limits<wchar_t>().min();
    auto max_unsigned = std::numeric_limits<wchar_t>().max();
    std::cout << "num bytes (signed): " << num_bytes_signed << '\n';
    std::cout << "min value (signed): " << +min_signed << '\n';
    std::cout << "max value (signed): " << +max_signed << '\n';
    std::cout << '\n';
    std::cout << "num bytes (unsigned): " << num_bytes_unsigned << '\n';
    std::cout << "min value (unsigned): " << +min_unsigned << '\n';
    std::cout << "max value (unsigned): " << +max_unsigned << '\n'; 
  }

  // code snippet 4
  {
    printf("short int limits\n");
    auto num_bytes_signed = sizeof(signed short int);
    auto min_signed = std::numeric_limits<signed short int>().min();
    auto max_signed = std::numeric_limits<signed short int>().max();
    auto num_bytes_unsigned = sizeof(unsigned short int);
    auto min_unsigned = std::numeric_limits<unsigned short int>().min();
    auto max_unsigned = std::numeric_limits<unsigned short int>().max();
    std::cout << "num bytes (signed): " << num_bytes_signed << '\n';
    std::cout << "min value (signed): " << min_signed << '\n';
    std::cout << "max value (signed): " << max_signed << '\n';
    std::cout << '\n';
    std::cout << "num bytes (unsigned): " << num_bytes_unsigned << '\n';
    std::cout << "min value (unsigned): " << min_unsigned << '\n';
    std::cout << "max value (unsigned): " << max_unsigned << '\n';
  }
  
  // code snippet 5
  {
    printf("int limits\n");
    auto num_bytes_signed = sizeof(signed int);
    auto min_signed = std::numeric_limits<signed int>().min();
    auto max_signed = std::numeric_limits<signed int>().max();
    auto num_bytes_unsigned = sizeof(unsigned int);
    auto min_unsigned = std::numeric_limits<unsigned int>().min();
    auto max_unsigned = std::numeric_limits<unsigned int>().max();
    std::cout << "num bytes (signed): " << num_bytes_signed << '\n';
    std::cout << "min value (signed): " << min_signed << '\n';
    std::cout << "max value (signed): " << max_signed << '\n';
    std::cout << '\n';
    std::cout << "num bytes (unsigned): " << num_bytes_unsigned << '\n';
    std::cout << "min value (unsigned): " << min_unsigned << '\n';
    std::cout << "max value (unsigned): " << max_unsigned << '\n';
  }

  // code snippet 6
  {
    printf("long int limits\n");
    auto num_bytes_signed = sizeof(signed long int);
    auto min_signed = std::numeric_limits<signed long int>().min();
    auto max_signed = std::numeric_limits<signed long int>().max();
    auto num_bytes_unsigned = sizeof(unsigned long int);
    auto min_unsigned = std::numeric_limits<unsigned long int>().min();
    auto max_unsigned = std::numeric_limits<unsigned long int>().max();
    std::cout << "num bytes (signed): " << num_bytes_signed << '\n';
    std::cout << "min value (signed): " << min_signed << '\n';
    std::cout << "max value (signed): " << max_signed << '\n';
    std::cout << '\n';
    std::cout << "num bytes (unsigned): " << num_bytes_unsigned << '\n';
    std::cout << "min value (unsigned): " << min_unsigned << '\n';
    std::cout << "max value (unsigned): " << max_unsigned << '\n';
  }

  // code snippet 7
  {
    printf("\nlong long int limits\n");
    auto num_bytes_signed = sizeof(signed long long int);
    auto min_signed = std::numeric_limits<signed long long int>().min();
    auto max_signed = std::numeric_limits<signed long long int>().max();
    auto num_bytes_unsigned = sizeof(unsigned long long int);
    auto min_unsigned = std::numeric_limits<unsigned long long int>().min();
    auto max_unsigned = std::numeric_limits<unsigned long long int>().max();
    std::cout << "num bytes (signed): " << num_bytes_signed << '\n';
    std::cout << "min value (signed): " << min_signed << '\n';
    std::cout << "max value (signed): " << max_signed << '\n';
    std::cout << '\n';
    std::cout << "num bytes (unsigned): " << num_bytes_unsigned << '\n';
    std::cout << "min value (unsigned): " << min_unsigned << '\n';
    std::cout << "max value (unsigned): " << max_unsigned << '\n';
  }

  // code snippet 8
  {
    printf("\nfloat limits\n");
    auto num_bytes = sizeof(float);
    auto min = std::numeric_limits<float>().min();
    auto max = std::numeric_limits<float>().max();
    std::cout << "num bytes: " << num_bytes << '\n';
    std::cout << "min value: " << min << '\n';
    std::cout << "max value: " << max << '\n';
  }


  // code snippet 9
  {
    printf("\ndouble limits\n");
    auto num_bytes = sizeof(double);
    auto min = std::numeric_limits<double>().min();
    auto max = std::numeric_limits<double>().max();
    std::cout << "num bytes: " << num_bytes << '\n';
    std::cout << "min value: " << min << '\n';
    std::cout << "max value: " << max << '\n';
  }
  
  // code snippet 10
  {
    printf("\nlong double limits\n");
    auto num_bytes = sizeof(long double);
    auto min = std::numeric_limits<long double>().min();
    auto max = std::numeric_limits<long double>().max();
    std::cout << "num bytes: " << num_bytes << '\n';
    std::cout << "min value: " << min << '\n';
    std::cout << "max value: " << max << '\n';
  }
  
  // code snippet 11
  {
    printf("\nbool limits\n");
    auto num_bytes = sizeof(bool);
    auto min = std::numeric_limits<bool>().min();
    auto max = std::numeric_limits<bool>().max();
    std::cout << "num bytes: " << num_bytes << '\n';
    std::cout << "min value: " << min << '\n';
    std::cout << "max value: " << max << '\n';
  }

  // code snippet 12
  {
    printf("------------------------- test typename size\n");
    are_equal<uint8_t, int8_t>();
    are_equal<uint8_t, uint32_t>();
    
    are_equal<signed char, int8_t>();
    are_equal<unsigned char, uint8_t>();
    
    are_equal<signed short int, int16_t>();
    are_equal<unsigned short int, uint16_t>();

    are_equal<signed int, int32_t>();
    are_equal<unsigned int, uint32_t>();

    are_equal<signed long int, int64_t>();
    are_equal<unsigned long int, uint64_t>();

    are_equal<signed long long int, int64_t>();
    are_equal<unsigned long long int, uint64_t>();
  }

  // code snippet 13
  {
    struct mystruct {
      uint64_t data1;
      uint64_t data2;
    };
    struct mystruct2 {
      uint64_t data1;
      uint16_t data2;
    };
    std::cout << "size: " << sizeof(mystruct) << '\n';
    std::cout << "size: " << sizeof(mystruct2) << '\n';
  }

  // code snippet 14
  {
    /* compiler's ability to perform type conversions from a 
     * smaller width type to a higher width type in order to 
     * optimize performance to reduce the possibility of overflows.
     **/
    int16_t s = 42;
    auto result = s + 42;
    std::cout << "size: " << sizeof(result) << '\n';
  }
  
  // code snippet 15
  {
    // compiler doesn't see a benefit to changing the size of either of the integers
    struct mystruct {
      uint16_t data1;
      uint16_t data2;
    };
    std::cout << "size: " << sizeof(mystruct) << '\n';
  }
  
  // code snippet 16
  {
    /*
     * Defining these bit fields does not prevent the compiler from 
     * changing the total size of the first integer from 16 bits to 64 bits.
     **/
    struct mystruct {
      uint16_t data1 : 2, data2 : 14;
      uint64_t data3;
    };
    std::cout << "size: " << sizeof(mystruct) << '\n';
  }

  // code snippet 17: pack the structure
  {
    // ask the compiler not allowed to make a substitution optimization
#pragma pack(push, 1)
    struct mystruct
    {
      uint64_t data1; // 8 bytes = 64 bits
      uint16_t data2; // 2 bytes = 16 bits
    };
#pragma pack(pop)
    std::cout << "pack size: " << sizeof(mystruct) << '\n';
  }

  // code snippet 18: pack structure
  {
#pragma pack(push, 1)
    struct mystruct {
      uint16_t data1;
      uint64_t data2;
    };
#pragma pack(pop)
    mystruct s;
    // the address is byte aligned, not cache aligned
    cout << "address is : " << &s << endl;
    cout << "size    is : " << sizeof(s) << endl;
  }

  // code snippet 19: align the packed structure
  {
    // #pragma pack macro is a hint, not a requirement
#pragma pack(push,1)
    struct alignas(16) mystruct
    {
      uint16_t data1;
      uint64_t data2;
    };
#pragma pack(pop)
    mystruct s;
    cout << "address is : " << &s << endl;
    cout << "size    is : " << sizeof(s) << endl;
    cout << "address data1 is : " << &s.data1 << endl;
    cout << "address data2 is : " << &s.data2 << endl;
  }

  // code snippet 20: size of pointer
  {
#pragma pack (push, 1)
    struct mystruct
    {
      // depends on CPU architecture: 4 bytes for 32-bit, 8 bytes for 64-bit 
      uint16_t* data1;
      uint64_t data2; // 8 bytes
    };
#pragma pack(pop)
    cout << "size    is : " << sizeof(mystruct) << endl;
  }
  
  return 0;
}

