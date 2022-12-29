using System;
using System.Text;
using static System.Math;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

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

  public static void Main(string[] args)
  {
    {
      var taskC = Task.Run(() => {
          Logger.Log("inside task C");
          Thread.Sleep(TimeSpan.FromSeconds(1D));
          Logger.Log("leaving task C");
        });
      Logger.Log($"Started task C. Status={taskC.Status}");

      Thread.Sleep(TimeSpan.FromSeconds(1D));
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}