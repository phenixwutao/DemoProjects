using System;
using System.Text;

class test
{
  static void FormatString(string stringToFormat)
  {
  stringToFormat.Replace("World", "Mars");
  }

  static string FormatReturningString(string stringToFormat)
  {
  return stringToFormat.Replace("Earth", "Mars");
  }

  static void Main(string[] args)
  {
    {
    Console.WriteLine("Hi! I'm your first Program. What is your name?");
    var name = Console.ReadLine();

    // string interpolation
    Console.WriteLine($"Hi {name}, it is very nice to meet you. We have a really fun journey ahead.");
    }

    {
      var greetings = "Hello World!";
      FormatString(greetings);
      Console.WriteLine(greetings);

      var anotherGreetings = "Good morning Earth!";
      Console.WriteLine(FormatReturningString(anotherGreetings));
      Console.WriteLine(anotherGreetings);
    }

    {
      string first = "Hello.";
      string second = first;
      Console.WriteLine((first == second));
      Console.WriteLine(string.Equals(first, second));
    }

    {
      float myFloat = 10f;
      double myDbl = 14d;
      decimal myDeci = 10m;
      Console.WriteLine("float " + myFloat + " double " + myDbl + " decimal " + myDeci);
    }
    Console.WriteLine();
  }
}

