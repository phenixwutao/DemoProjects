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
      var taskB = Task.Factory.StartNew(() =>
        {
          Logger.Log("inside task B");
          Thread.Sleep(TimeSpan.FromSeconds(3D));
          Logger.Log("leaving task B");
        });
      Logger.Log($"Started task B. Status={taskB.Status}");

      Thread.Sleep(TimeSpan.FromSeconds(3D));
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}