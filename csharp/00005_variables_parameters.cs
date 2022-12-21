using System;
using System.Text;

class Test
{
  public class StringBuilder
  {
    public string name;
    public StringBuilder(string s)
    {
      name = s;
    } 
  }

  static int xx;

  static void modifyx(ref int x)
  {
    x = x + 1;
  }

  static void outputy(ref int x, out int y)
  {
    x = x + 1;
    y = x*2;
  }

  static int add(int s1, int s2)
  {
    Console.WriteLine("s1={0}, s2={1}", s1, s2);
    return s1 + s2;
  }

  static int addDefaultArg(int s1 = 0, int s2 = 0, int s3 = 0)
  {
    return s1 + s2 + s3;
  }

  static void Main()
  {
    {
      StringBuilder ref1 = new StringBuilder("object1");

      StringBuilder ref2 = new StringBuilder("object2");
      StringBuilder ref3 = ref2;
      Console.WriteLine("xx={0}", xx);

      decimal de = default(decimal);
      double dbl = default(double);
      Console.WriteLine("dbl={0}", dbl);

      int a = 9;
      modifyx(ref a);
      Console.WriteLine("a={0}", a);

      int b;
      outputy(ref a, out b);
      Console.WriteLine("a={0}, b={1}", a, b);

      outputy(ref a, out int y1); // declare variable y1 on fly
      outputy(ref a, out _);  // discard the output parameter by _
      Console.WriteLine("a={0}, y1={1}", a, y1);

      int t1 = 6;
      int t2 = 20;
      var sum1 = add(s2:t2, s1:t1); //identify arguments by its position
      Console.WriteLine("sum1= {0}", sum1);
      sum1 = add(s1:t1, s2:t2);
      Console.WriteLine("sum1= {0}", sum1);

      var sum2 = addDefaultArg(s3:8);
      Console.WriteLine("sum2= {0}", sum2);
    }

    // test operators
    {
      string s1 = null;
      string s2 = s1 ?? "zero";
      Console.WriteLine("s2 is " + s2);
      s1 = "hello";
      s2 = s1 ?? "zero";
      Console.WriteLine("s2 is " + s2);

      // type pattern matching case when : works for newer version C# compiler
      // object x = true;
      // switch (x)
      //   {
      //   case bool b when b == true: // Fires only when b is true
      //   Console.WriteLine ("True!");
      //   break;
      //   case bool b:
      //   Console.WriteLine ("False!");
      //   break;
      //   }
      string ff = null;
      switch (ff)
      {
        case null:
        Console.WriteLine("ff is null value");
        break;
      }

      for (int i = 0, prevFib = 1, curFib = 1; i < 10; i++)
      {
        Console.WriteLine (prevFib);
        int newFib = prevFib + curFib;
        prevFib = curFib; curFib = newFib;
      }

      foreach (char c in "beer") // c is the iteration variable
        Console.WriteLine (c);
    }
    Console.WriteLine();
    // Capriccio 1987
    // Actor: Bridgette Barrett, Rachael Blake, Hannah Bella Bowden, Emily Browning
    // Sleeping Beauty 2011
  }

}
