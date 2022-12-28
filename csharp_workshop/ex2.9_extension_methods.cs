using System;
using System.Text;
using static System.Math;

  public static class StringExtensions
  {
    public static void Print(this string text)
    {
      Console.WriteLine(text);
    }
  }

public class Test
{

  public static void Main(string[] args)
  {
    {
      string name = "Adam";
      name.Print();
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}