using System;
using System.Text;
using static System.Math;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using System.Globalization;

public static class Logger
{
  public static void Log(string message)
  {
    // :T time-formatted string  :00 add leading zero
    Console.WriteLine($"{DateTime.Now:T}[{Thread.CurrentThread.ManagedThreadId:00}] {message}");
  }
}

public class Test
{
  private static long Fibonacci(int n)
  {
    if (n <= 2L)
      return 1L;
    return Fibonacci(n-1) + Fibonacci(n-2);
  }

  public static void Main(string[] args)
  {
    {
      for(int k=1; k<=4; ++k)
      {
        Console.WriteLine($"calculate  Fibonacci({k*11})");
        Task.Run(() => {
          var now = DateTime.Now;
          int number = k*11;
          var fib = Fibonacci(number);
          var duration = DateTime.Now.Subtract(now);
          Logger.Log($"Fibonacci {number:N0} = {fib:N0} (elapsed time: {duration.TotalSeconds:N0} secs)");
          });

        Thread.Sleep(TimeSpan.FromSeconds(2D));
      }
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}