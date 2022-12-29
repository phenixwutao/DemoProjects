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

  private static string TaskBActivity()
  {
    Logger.Log($"Inside {nameof(TaskBActivity)}");
    Thread.Sleep(TimeSpan.FromSeconds(2));
    Logger.Log($"Leaving {nameof(TaskBActivity)}");
    return "";
  }
  private static void TaskCActivity()
  {
    Logger.Log($"Inside {nameof(TaskCActivity)}");
    Thread.Sleep(TimeSpan.FromSeconds(1));
    Logger.Log($"Leaving {nameof(TaskCActivity)}");
  }

  public static void Main(string[] args)
  {
    {
      Logger.Log("Starting main ...");
      var taskA = Task.Run(()=> {
          Logger.Log($"Inside TaskA");
          Thread.Sleep(TimeSpan.FromSeconds(5));
          Logger.Log($"Leaving TaskA");
        });

      var taskB = Task.Run(TaskBActivity);
      var taskC = Task.Run(TaskCActivity);

      var timeout = TimeSpan.FromSeconds(new Random().Next(4,7)); // wait for 4-7 seconds
      // var timeout = TimeSpan.FromSeconds(7);
      Logger.Log($"Waiting max {timeout.TotalSeconds} seconds ...");

      var allDone = Task.WaitAll(new[] {taskA, taskB, taskC}, timeout);
      // var allDone = Task.WaitAll(new[] {taskA, taskB, taskC});
      Logger.Log($"AllDone = {allDone}, TaskA={taskA.Status}, TaskB={taskB.Status}, TaskC={taskC.Status}");
    }
    //Thread.Sleep(TimeSpan.FromSeconds(4D));
    Console.WriteLine();

    {
      Logger.Log("Starting main ...");
      var taskA = Task.Run(()=> {
          Logger.Log($"Inside TaskA");
          Thread.Sleep(TimeSpan.FromSeconds(5));
          Logger.Log($"Leaving TaskA");
        });

      var taskB = Task.Run(TaskBActivity);
      var taskC = Task.Run(TaskCActivity);


      var allDone = Task.WaitAll(new Task[] {taskA, taskB, taskC}, 7000);
      Logger.Log($"AllDone = {allDone}, TaskA={taskA.Status}, TaskB={taskB.Status}, TaskC={taskC.Status}");
    }
    Console.WriteLine();
  }
}