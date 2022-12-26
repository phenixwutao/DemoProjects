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

  static void Main(string[] args)
  {
    {
      // tasks conveniently propagate exceptions
      // Start a Task that throws a NullReferenceException:
      Task task = Task.Run (() => { throw null; });
      try
      {
        task.Wait(); // exception is re-thrown by wait()
      }
      catch (AggregateException aex)
      {
      if (aex.InnerException is NullReferenceException)
        Console.WriteLine ("Exception Null!");
      else
        throw;
      }
    }

    {
      // Task<TResult> can be thought of as a "future", in that it
      // encapsulates a Result that becomes available later in time.
      Task<int> primeNumberTask = Task.Run (() =>
        Enumerable.Range (2, 3000000).Count (n =>
          Enumerable.Range (2, (int)Math.Sqrt(n)-1).All (i => n % i > 0)));
      Console.WriteLine ("Task running...");
      Console.WriteLine ("The answer is " + primeNumberTask.Result);
    }


    // Thread.Sleep (2000);
    {
      Task<int> primeNumberTask = Task.Run (() =>
        Enumerable.Range (2, 3000000).Count (n =>
          Enumerable.Range (2, (int)Math.Sqrt(n)-1).All (i => n % i > 0)));

      // continuation: the exception is re-thrown when the continuation code
      // calls awaiter.GetResult().
      var awaiter = primeNumberTask.GetAwaiter();
      awaiter.OnCompleted (() =>
        {
          int result = awaiter.GetResult();
          Console.WriteLine ("awaiter {0}", result); // Writes result
        });
    }
    Thread.Sleep (3000);

    {
      Task<int> primeNumberTask = Task.Run (() =>
        Enumerable.Range (2, 3000000).Count (n =>
          Enumerable.Range (2, (int)Math.Sqrt(n)-1).All (i => n % i > 0)));

      primeNumberTask.ContinueWith (antecedent =>
        {
          int result = antecedent.Result;
          Console.WriteLine ("ContinueWith " + result); // Writes 123
        });
    }
    Thread.Sleep (3000);


    Console.WriteLine();
  }

}
