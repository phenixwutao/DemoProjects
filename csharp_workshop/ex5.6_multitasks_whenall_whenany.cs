using System;
using System.Text;
using static System.Math;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using System.Globalization;
using System.Linq;

public static class Logger
{
  public static void Log(string message)
  {
    // :T time-formatted string  :00 add leading zero
    Console.WriteLine($"{DateTime.Now:T}[{Thread.CurrentThread.ManagedThreadId:00}] {message}");
  }
}

public class CarSale
{
  public CarSale(string name, double salePrice)
  {
    Name = name; SalePrice = salePrice;
  }
  public string Name {get;}
  public double SalePrice {get;}
}

public interface ISaleLoader
{
  IEnumerable<CarSale> FetchSales();
}

public static class SalesAggregator
{
  public static Task<double> Average(IEnumerable<ISaleLoader> loaders)
  {
    var loaderTasks = (loaders.Select(ldr => Task.Run(ldr.FetchSales)));
    return Task.WhenAll(loaderTasks).ContinueWith(tasks => 
      {
      var average = tasks.Result.SelectMany(t => t)
                          .Average(car => car.SalePrice);
      return average;
      });
  }
}

public class SalesLoader : ISaleLoader
{
  private readonly Random _random;
  private readonly string _name;
  public SalesLoader(int id, Random rand)
  {
    _name = $"Loader#{id}";
    _random = rand;
  }

  public IEnumerable<CarSale> FetchSales()
  {
    var delay = _random.Next(1,3);
    Logger.Log($"FetchSales {_name} sleeping for {delay} seconds...");
    Thread.Sleep(TimeSpan.FromSeconds(delay));

    var sales = Enumerable.Range(1, _random.Next(1,5)).Select( n => GetRandomCar()).ToList();

    foreach(var car in sales)
    {
      Logger.Log($"FetchSales {_name} found: {car.Name} @ {car.SalePrice:N2}");
    }
    return sales;
  }

  private readonly string[] _carNames = {"Ford", "BMW", "Fiat", "Mercedes", "Porsche"};

  private CarSale GetRandomCar()
  {
    var nameIndex = _random.Next(_carNames.Length);
    return new CarSale( _carNames[nameIndex], _random.NextDouble()*1000 );
  }
}

public class Test
{

  public static void Main(string[] args)
  {
    {
      var random = new Random();
      const int MaxSaleHubs = 10;
      const int maxDelay = 5;
      var loaders = Enumerable.Range(1, random.Next(1, MaxSaleHubs))
                              .Select(n => new SalesLoader(n, random)).ToList();
      var averageTask = SalesAggregator.Average(loaders);
      var hasCompleted = averageTask.Wait(TimeSpan.FromSeconds(maxDelay));
      var average = averageTask.Result;
      if (hasCompleted)
      {
        Logger.Log($"Average={average:N2}");
      }
      else
      {
        Logger.Log("Timeout!");
      }
    }

    Thread.Sleep(TimeSpan.FromSeconds(4D));
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}