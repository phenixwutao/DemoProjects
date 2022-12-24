using System;
using System.Text;


delegate int MyProcessor (int i);

class test
{

  static void Main()
  {
    {
      // Capturing Outer Variable
      int factor = 2;
      Func<int,int> multiplier = n => n * factor;
      factor = 10;
      Console.WriteLine("multiplier(3) = {0}", multiplier(3));
    }

    {
      Func<int> increment = NaturalIncrement();
      Console.WriteLine(increment());
      Console.WriteLine(increment());
    }

    //Capturing iteration variable
    {
      Action[] actions = new Action[3];
      for (int i = 0; i < 3; i++)
        actions [i] = () => Console.Write (i);

      foreach (Action a in actions) 
        a(); // 333
      Console.WriteLine();
    }

    {
      // anonymous method
      MyProcessor squr = delegate (int x) { return x * x; };
      MyProcessor sqr2 = s => s * s;
      Console.WriteLine(squr(4));
      Console.WriteLine(sqr2(3));
    }

    Console.WriteLine();
  }


  static Func<int> NaturalIncrement()
  {
    int seed = 0;
    return () => seed++; // Returns a closure
  }
}
