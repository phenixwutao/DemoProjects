using System;
using System.Net;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

using System.Xml;

using System.Runtime.CompilerServices;
using System.Dynamic;

using System.Globalization;
using System.Threading;
using System.Threading.Tasks;

using System.Linq;  //Enumerable

class test
{
  public static Task<int> GetPrimesCountAsync(int start, int count)
  {
    return Task.Run (() =>
      ParallelEnumerable.Range (start, count).Count (n =>
      Enumerable.Range (2, (int) Math.Sqrt(n)-1).All (i => n % i > 0)));
  }

  static void Main(string[] args)
  {

    {
      for (int i = 0; i < 10; i++)
        {
          var awaiter = GetPrimesCountAsync (i*1000000 + 2, 1000000).GetAwaiter();
          awaiter.OnCompleted (() =>
            Console.WriteLine (awaiter.GetResult() + " primes between... "));
        Thread.Sleep (3000);
        }
        // Thread.Sleep (4000);
        Console.WriteLine ("Done");
    }

    {
    }




    Console.WriteLine();
  }

}
