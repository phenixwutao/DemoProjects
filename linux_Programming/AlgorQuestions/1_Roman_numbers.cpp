#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int RomanToInt(string roman) {
    int number = 0;
    char prev = '\0';

    for (auto letter : roman) {
        if (letter == 'I') {
            number++;
            prev = 'I';
        } else if (letter == 'V') {
            if (prev == 'I')
                number = number + 3;
            else
                number = number + 5;
            prev = 'V';
        } else if (letter == 'X') {
            if (prev == 'I')
                number = number + 8;
            else
                number = number + 10;
            prev = 'X';
        } else if (letter == 'L') {
            if (prev == 'X')
                number = number + 30;
            else
                number = number + 50;
            prev = 'L';
        } else if (letter == 'C') {
            if (prev == 'X')
                number = number + 80;
            else
                number = number + 100;
            prev = 'C';
        } else if (letter == 'D') {
            if (prev == 'C')
                number = number + 300;
            else
                number = number + 500;
            prev = 'D';
        } else if (letter == 'M') {
            if (prev == 'C')
                number = number + 800;
            else
                number = number + 1000;
            prev = 'M';
        }
    }

    return number;
}


std::string IntToRoman(int num)
{
  std::vector<std::pair<int, std::string>> romans = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}};

  std::string result;
  for(auto& [x, letter] : romans)
  {
    //int count = num/it.first;
    while(num >= x)
    {
      result += letter;
      num -= x;
    }
  }
  return result;
}


    string intToRoman(int num) {
        string M[4] = {"","M","MM","MMM"};
        string C[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string X[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string I[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        return M[num/1000]+C[(num/100)%10]+X[(num/10)%10]+I[num%10];
    }

class Solution {
public:
    
    void add(string &s, int &n, string c, int j)
    {
        int count = n/j;
        while(count--)
            s += c;
        n %= j;
    }    
    
    string intToRoman(int n) 
    {        
        string s;
        add(s, n, "M", 1000);        
        add(s, n, "CM", 900);        
        add(s, n, "D", 500);        
        add(s, n, "CD", 400);        
        add(s, n, "C", 100);        
        add(s, n, "XC", 90);        
        add(s, n, "L", 50);        
        add(s, n, "XL", 40);        
        add(s, n, "X", 10);        
        add(s, n, "IX", 9);   
        add(s, n, "V", 5);        
        add(s, n, "IV", 4);   
        add(s, n, "I", 1);   
        return s;
    }
};

int main()
{
  std::cout << RomanToInt("III") << '\n';
  std::cout << RomanToInt("LVIII") << '\n';
  std::cout << RomanToInt("MCMXCIV") << '\n';

  std::cout << intToRoman(3) << '\n';
  std::cout << intToRoman(58) << '\n';
  std::cout << intToRoman(1994) << '\n';

  std::cout << IntToRoman(3) << '\n';
  std::cout << IntToRoman(58) << '\n';
  std::cout << IntToRoman(1994) << '\n';
  return 0;
}

#if 0
class Solution {
    public String intToRoman(int num) {
        
        TreeMap<Integer, String> map = new TreeMap<>((a,b) -> (b - a));
        map.put(1000, "M");
        map.put(900, "CM");
        map.put(500, "D");
        map.put(400, "CD");
        map.put(100, "C");
        map.put(90, "XC");
        map.put(50, "L");
        map.put(40, "XL");
        map.put(10, "X");
        map.put(9, "IX");
        map.put(5, "V");
        map.put(4, "IV");
        map.put(1, "I");
        
        String result = "";
        for (Map.Entry<Integer, String> entry : map.entrySet()) {
            while (num >= entry.getKey()) {
                result += entry.getValue();
                num -= entry.getKey();
            }
        }
        return result;
        
    }
}
#endif
