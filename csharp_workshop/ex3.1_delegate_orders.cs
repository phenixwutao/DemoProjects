using System;
using System.Text;
using static System.Math;
using System.Collections.Generic;

namespace MyOrder
{
    public delegate bool DateValidationHandler(DateTime datetime);
    public class Order {
        private readonly DateValidationHandler _orderDateValidator;
        private readonly DateValidationHandler _deliveryDateValidator;
        public DateTime OrderDate {get; set;}
        public DateTime DeliveryDate {get; set;}
        public Order(DateValidationHandler orderDateValidator, DateValidationHandler deliveryDateValidator)
        {
            _orderDateValidator = orderDateValidator;
            _deliveryDateValidator = deliveryDateValidator;
        }
        public bool IsValid() => _orderDateValidator(OrderDate) && _deliveryDateValidator(DeliveryDate);
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
}

public class Test
{

  public static void Main(string[] args)
  {
    {
        // customised delegates
        var orderValidator = new MyOrder.DateValidationHandler(MyOrder.DateValidation.IsPastDate);
        var deliveryValidator = new MyOrder.DateValidationHandler(MyOrder.DateValidation.IsWeekendDate);
        var order = new MyOrder.Order(orderValidator, deliveryValidator)
        {
            OrderDate = DateTime.Today.AddDays(-10),
            DeliveryDate = new DateTime(2022,12,31)
        };
        Console.WriteLine($"Ordered {order.OrderDate : dd-MMM-yy}");
        Console.WriteLine($"Delivered {order.DeliveryDate : dd-MMM-yy}");
        Console.WriteLine($"IsValid {order.IsValid()}");
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}