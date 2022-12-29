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
  public static void Main(string[] Args)
        {
            Logger.Log("Start...");
            Task.Run(GetStockPrice).ContinueWith((prev) =>
                {
                    Logger.Log($"GetPrice returned {prev.Result:N3}, status={prev.Status}");
                    var newPrice = prev.Result + 10;
                    Logger.Log($"new Price {newPrice:N3}");
                });

          Thread.Sleep(TimeSpan.FromSeconds(3.5D));
        }

        private static double GetStockPrice()
        {
            Logger.Log("Inside GetStockPrice");
            Thread.Sleep(TimeSpan.FromSeconds(3D));
            return new Random().NextDouble() * 100D;
        }
}

