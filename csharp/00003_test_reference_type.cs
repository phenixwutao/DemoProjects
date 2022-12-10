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
    }
  }

}
