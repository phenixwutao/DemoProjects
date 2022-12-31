using System;
using System.Text;
using static System.Math;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
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
  private static async Task BuildGreetings()
      {
            var message = "Morning";
            Logger.Log($"{message}");

            await Task.Delay(TimeSpan.FromSeconds(10D));

            message += "...Afternoon";
            Logger.Log($"{message}");

            await Task.Delay(TimeSpan.FromSeconds(1D));

            message += "...Evening";
            Logger.Log($"{message}");
      }

  public static async Task Main()
  {
    {
      Logger.Log("Starting ...");
      await BuildGreetings();
      Logger.Log("Press enter:");
      Thread.Sleep(TimeSpan.FromSeconds(2D));
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }

}