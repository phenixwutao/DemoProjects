// C# code chapter 2
using System;
class Test
{
  static void Main()
  {
    int x = 12*30;
    Console.WriteLine(x);
    Console.WriteLine(FeetToInches(30));
    Console.WriteLine(FeetToInches(100));
    int @class  = 1;
    Console.WriteLine(@class);
    var mess = @class.ToString();
    Console.WriteLine("convert to string: " + mess);
  }

  static int FeetToInches(int feet)
  {
    return feet * 12;
  }
}
