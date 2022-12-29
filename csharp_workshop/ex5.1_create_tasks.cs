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


public class TaskExamples
{

  public static void Main(string[] args)
  {
    {
      Logger.Log("Create task A");
      var taskA = new Task(
        ()=>{
          Logger.Log("inside task A");
          Thread.Sleep(TimeSpan.FromSeconds(5D));
          Logger.Log("leaving task A");
          });
      Logger.Log($"Starting task A 1. Status = {taskA.Status}");
      taskA.Start();
      Logger.Log($"Starting task A 2. Status = {taskA.Status}");

      Thread.Sleep(TimeSpan.FromSeconds(5D)); // wait for task to finish
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}

