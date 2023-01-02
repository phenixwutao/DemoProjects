// See https://aka.ms/new-console-template for more information
using System;
using System.Text;

public class Test
{
  // test record type
  public record persion
  {
    public string? Name;
  }
  public static void Main(string[] args)
  {
    persion p1 = new persion() {Name = "Judith"};
    Console.WriteLine("Hello, World!");
    Console.WriteLine($"p1 name is {p1.Name}");
  }
}