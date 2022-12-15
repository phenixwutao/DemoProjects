// C# code chapter 2

using System;
class Point
{
  public int x;
  public int y;
}
struct Deal
{
  int ID;
}

class Test
{
  public class Dude
  {
    public string Name;
    public Dude (string n) { Name = n; }
  }

  static void Main()
  {
    Point p1 = new Point();
    p1.x = 7;
    Point p2 = p1;
    Console.WriteLine(p1.x);
    Console.WriteLine(p2.x);

    p1.x = 9;
    Console.WriteLine(p1.x);
    Console.WriteLine(p2.x);

    Point p3 = null;
    // Deal deal = null; // compile time error: Deal is valye type

    int i = 5;
    System.Int32 j = 6;
    Console.WriteLine(i+j);

    int million = 1_00;
    Console.WriteLine(million);

    Console.WriteLine ( 1.0.GetType()); // Double (double)
    Console.WriteLine ( 1E06.GetType()); // Double (double)
    Console.WriteLine ( 1.GetType()); // Int32 (int)
    Console.WriteLine ( 0xF0000000.GetType()); // UInt32 (uint)
    Console.WriteLine (0x100000000.GetType()); // Int64 (long)    

    {
      float f = 1.0F;
      double d1 = 1D;
      decimal d2 = 1.0M;
      uint ui = 1U;
      ulong uj = 1UL;
      long k = 1L; 
    }

    {
      int i1 = 100000001;
      float f = i1;
      int i2 = (int)f;
      Console.WriteLine(i1);
      Console.WriteLine(f);
      Console.WriteLine(i2); // i2 is 100000000
    }

    {
      int xx = 0, yy = 0;
      Console.WriteLine (xx++); // Outputs 0; x is now 1
      Console.WriteLine (++yy); // Outputs 1; y is now 1   

      int a = int.MinValue;
      Console.WriteLine(a);
      a--;
      Console.WriteLine(a);
      Console.WriteLine (a == int.MaxValue); // True   
    }

    {
      Console.WriteLine("test checked");
      try {
      int a = 1000000;
      int b = 1000000;
      int c = checked (a * b);
      Console.WriteLine(c);
      }
      catch(Exception e)
      {
        Console.WriteLine("Exception caught:\n{0}", e);
      }

      Console.WriteLine("test unchecked");
      int xx = int.MaxValue;
      int yy = unchecked (xx + 1);
      unchecked { int z = xx + 1; }
      Console.WriteLine(xx);
      Console.WriteLine(yy);
      Console.WriteLine (double.IsNaN (0.0 / 0.0)); // True
    }

    // check rounding errors and decimal points
    {
      float x = 0.1f; // Not quite 0.1
      Console.WriteLine (x + x + x + x + x + x + x + x + x + x); // 1.0000001
      decimal m = 1M / 6M; // 0.1666666666666666666666666667M
      double d = 1.0 / 6.0; // 0.16666666666666666
      Console.WriteLine("d={0}", d);
      Console.WriteLine("m={0}", m);

      decimal notQuiteWholeM = m+m+m+m+m+m; // 1.0000000000000000000000000002M
      double notQuiteWholeD = d+d+d+d+d+d; // 0.99999999999999989
      Console.WriteLine("notQuiteWholeM={0}", notQuiteWholeM);
      Console.WriteLine("notQuiteWholeD={0}", notQuiteWholeD);
    }

    {
      Dude d1 = new Dude ("John");
      Dude d2 = new Dude ("John");
      Console.WriteLine (d1 == d2); // False
      Dude d3 = d1;
      Console.WriteLine (d1 == d3); // True

      string escaped = "First Line\r\nSecond Line";
      string verbatim = @"First Line
Second Line";
      // True if your text editor uses CR-LF line separators:
      Console.WriteLine (escaped);
      Console.WriteLine (verbatim);
      Console.WriteLine (escaped == verbatim);

      string xml = @"<customer id=""123""></customer>";
      Console.WriteLine (xml); // <customer id="123"></customer>

      int x = 4;
      // calling ToString method or equivalent
      Console.WriteLine ($"A square has {x} sides"); // Prints: A square has 4 sides

      string s = $"255 in hex is {byte.MaxValue:X2}"; // X2 = 2-digit hexadecimal
      // Evaluates to "255 in hex is FF"
      Console.WriteLine(s) ;

      // ternary conditional operator, wrap the entire expression in parentheses:
      bool b = true;
      Console.WriteLine ($"The answer in binary is {(b ? 1 : 0)}");

      // Note that $ must appear before @ prior to C# 8:
      string s2 = $@"this interpolation spans {
      x} lines";
      Console.WriteLine(s2) ;


      // Constant interpolated strings (C# 10)
      const string greeting = "Hello";
       string message = $"{greeting}, world";
      Console.WriteLine(message) ;

    }
  }

}
