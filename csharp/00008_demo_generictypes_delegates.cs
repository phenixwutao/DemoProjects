using System;
using System.Text;


class test
{
  delegate int Transformer (int x);

  static int Square(int x) => x*x;

  class util
  {
    public static void transform(int[] values, Transformer t)
    {
      for(int i = 0; i<values.Length; ++i)
        values[i] = t(values[i]);
    }
  }

  static void Main()
  {
    {
      Transformer t = Square;
      // Transformer t = new Transformer (Square); // same as above

      int result = t(3);
      Console.WriteLine(result);
      int[] values = {1,2,3};
      util.transform(values, Square);
      foreach( int i in values)
      {
        Console.WriteLine(i + " ");
      }
    }

    {
    }


    Console.WriteLine();
  }
}
