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

  public static void Main(string[] args)
  {
    {
      var outerTask = Task.Run( () => {
        Logger.Log("inside outerTask");

        var inner1 = Task.Run(() => {
          Logger.Log("inside inner1");
          Thread.Sleep(TimeSpan.FromSeconds(3D));
          });

        var inner2 = Task.Run(() => {
          Logger.Log("inside inner2");
          Thread.Sleep(TimeSpan.FromSeconds(2D));          
          });

        Logger.Log("Calling WaitAny on outerTask");
        var doneIndex = Task.WaitAny(inner1,inner2);
        Logger.Log($"Waitany index={doneIndex}");
        Logger.Log("leaving outerTask");
        });

    }
    Thread.Sleep(TimeSpan.FromSeconds(4D));
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}