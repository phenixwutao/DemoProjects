using System;
using System.Text;
using static System.Math;
using System.Collections.Generic;

public class Test
{
    private static string MyMethod(string name, int age)
    {
        return $"{name}@{age}";
    }
    private static void MyMethod2(string name, int age)
    {
        Console.WriteLine($"{name} and {age}");
    }

    public static class DateValidation {
        public static bool IsWeekendDate(DateTime date)
        {
            Console.WriteLine("called IsWeekendDate");
            return date.DayOfWeek == DayOfWeek.Saturday || date.DayOfWeek == DayOfWeek.Sunday;
        }
        public static bool IsPastDate(DateTime date)
        {
            Console.WriteLine("called IsPastDate");
            return date < DateTime.Today;
        }
    }

  public static void Main(string[] args)
  {
    {
        // Func delegate return a value type, which is the last argument in generics
        Func<string,int,string> funcA = MyMethod;
        Console.WriteLine($"funcA {funcA("Louis",2)}");

        // Action delegate do certain work, return void
        Action<string,int> actionA = MyMethod2;
        actionA("Louis",2);

        // use Func delegate by calling it
        Func<DateTime,bool> orderDateValidator = DateValidation.IsPastDate;
        Func<DateTime,bool> deliverDateValidator = DateValidation.IsWeekendDate;
        Console.WriteLine($"orderDateValidator {orderDateValidator(DateTime.Today.AddDays(-10))}");
        Console.WriteLine($"orderDateValidator {deliverDateValidator(new DateTime(2022,12,31))}");
    }
    Console.WriteLine();

    {
        // assign and invoke delegate functions
        var orderDateValidator = new Func<DateTime,bool>(DateValidation.IsPastDate);
        var deliverDateValidator = new Func<DateTime,bool>(DateValidation.IsWeekendDate);

        // Invoke delegate by using the null-coalescing operator
        var validOrder = orderDateValidator?.Invoke(DateTime.Today.AddDays(-10));
        var validDeliver = deliverDateValidator?.Invoke(new DateTime(2022,12,31));
        Console.WriteLine($"validOrder {validOrder}");
        Console.WriteLine($"validDeliver {validDeliver}");

    }
    Console.WriteLine();
  }
}