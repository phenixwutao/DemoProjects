using System;
using System.IO; // File class
using System.Text;
using static System.Math;
using System.Collections.Generic;

public class Test
{
    static string RemoveAtSign(string address) => address.Replace("@", "");
    static string RemoveDots(string address) => address.Replace(".", "");
    
  public static void Main(string[] args)
  {
    {
        Func<string,string> emailFormatter = RemoveDots;
        const string Address = "admin@google.com";
        var first = emailFormatter(Address);
        Console.WriteLine($"First={first}");

        emailFormatter += RemoveAtSign;
        var second = emailFormatter(Address);
        Console.WriteLine($"Second={second}");

    }
    Console.WriteLine();

    {

    }
    Console.WriteLine();
  }
}