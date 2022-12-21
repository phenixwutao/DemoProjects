using System;
using System.Text;


class test
{
  delegate int Transformer (int x);
  public delegate void ProgressReporter(int percentComplete);

  static int Square(int x) => x*x;

  class util
  {
    public static void transform(int[] values, Transformer t)
    {
      for(int i = 0; i<values.Length; ++i)
        values[i] = t(values[i]);
    }

    public static void HardWork(ProgressReporter p)
    {
      for(int i=0; i < 10; ++i)
      {
        p (i * 10);
        System.Threading.Thread.Sleep(100);
      }
    }

    public static void GenericTransform<T>(T[] values, GenericTransformer<T> t)
    {
      for (int i = 0; i < values.Length; ++i)
      {
        values[i] = t(values[i]);
      }
    }
  }

  static void WriteProgressToConsole(int percentComplete)
              => Console.WriteLine(percentComplete);

  static void WriteProgressToFile(int percentComplete)
         => System.IO.File.WriteAllText("progress.txt", percentComplete.ToString());

  class X
  {
    public void InstanceProgress (int percentComplete)
            => Console.WriteLine (percentComplete);
  }         

  // generic delegate
  public delegate T GenericTransformer<T>(T arg);


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
      Console.WriteLine("-------- start ProgressReporter");
      ProgressReporter p = null;
      p += WriteProgressToConsole;
      p += WriteProgressToFile;
      util.HardWork(p);

      // delegate is assigned to instance method
      X xobj = new X();
      ProgressReporter p2 = xobj.InstanceProgress;
      p2(99);

      // Target and Method properties
      Console.WriteLine(p2.Target);
      Console.WriteLine(p2.Method);
    }

    {
      Console.WriteLine("-------- start generic tramsform");
      int[] values = {1,2,3,4};
      util.GenericTransform(values, Square);
      foreach(int k in values)
        Console.WriteLine(k + " ");
    }


    Console.WriteLine();
  }
}
