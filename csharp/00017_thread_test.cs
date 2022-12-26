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

static void WriteY()
{
  for(int i=0; i<10; ++i)
    Console.WriteLine("Y");
  Console.WriteLine ("thread name: "+Thread.CurrentThread.Name);
  Console.WriteLine ("thread state 1 : "+Thread.CurrentThread.ThreadState + 
                     " IsAlive: " + Thread.CurrentThread.IsAlive);
}
  static void Main(string[] args)
  {
    {
      Thread t = new Thread(WriteY);
      Console.WriteLine ("thread state 2: "+t.ThreadState + " IsAlive: " + t.IsAlive);
      t.Start();
      Console.WriteLine ("thread state 3: "+t.ThreadState + " IsAlive: " + t.IsAlive + ", IsBackground: " + t.IsBackground);
      Thread.Sleep (1000);
      Console.WriteLine ("thread state 4: "+t.ThreadState + " IsAlive: " + t.IsAlive);
      t.Join();
      Console.WriteLine ("thread state 5: "+t.ThreadState + " IsAlive: " + t.IsAlive);
    for(int i=0; i<10; ++i)
      Console.WriteLine("X");  
    }

    {
      Console.WriteLine("------------- test thread 2");  
      bool done = false;
      ThreadStart action = () =>
      {
      if (!done) { done = true; Console.WriteLine ("Done"); }
      };
      new Thread (action).Start();
      action();
    }

    {
    }

    {
      Thread worker = new Thread(() => {
        Console.WriteLine("Thread: please input a number> ");
        Console.ReadLine();
        });
      if (args.Length > 0)
        worker.IsBackground = true;
      worker.Start();
    }

    {
      Task.Run (() => Console.WriteLine ("Hello from the thread pool"));
      ThreadPool.QueueUserWorkItem (notUsed => Console.WriteLine ("Hello from old ThreadPool.QueueUserWorkItem"));
    }

    {
      Task task = Task.Run (() =>
        {
        Console.WriteLine ("Fooo awaiting task to complete");
        Thread.Sleep (1000);
        });
      Console.WriteLine ("task.IsCompleted " + task.IsCompleted); // False
      task.Wait(); // Blocks until task is complete
    }

    {
      // get thread returned result
      Task<int> task = Task.Run (() => { Console.WriteLine ("Foo"); return 3; });
      Console.WriteLine("result is {0}", task.Result);
    }

    {
      Task<int> primeNumberTask = Task.Run (() =>
        Enumerable.Range (2, 3000000).Count (n =>
          Enumerable.Range (2, (int)Math.Sqrt(n)-1).All (i => n % i > 0)));
      Console.WriteLine ("Task running...");
      Console.WriteLine ("The answer is " + primeNumberTask.Result);


    }

    {
      Task<int> primeNumberTask = Task.Run (() =>
        Enumerable.Range (2, 3000000).Count (n =>
          Enumerable.Range (2, (int)Math.Sqrt(n)-1).All (i => n % i > 0)));
      Console.WriteLine ("Task running...");
      var awaiter = primeNumberTask.GetAwaiter();
      awaiter.OnCompleted (() =>
      {
      int result = awaiter.GetResult();
      Console.WriteLine ("awaiter get result {0}", result); // Writes result
      });
    }

    Console.WriteLine();
  }

}
