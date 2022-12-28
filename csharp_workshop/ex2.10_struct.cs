using System;
using System.Text;
using static System.Math;

public class Test
{

public struct Point
{
  public readonly int X;
  public readonly int Y;
  
  public Point(int x, int y)
  {
    X = x;
    Y = y;
  }

  public double DistanceTo(Point p)
  {
    return DistanceBetween(this, p);
  }

  public static double DistanceBetween(Point p1, Point p2)
  {
    return Math.Sqrt((p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y));
  }
}

// readonly struct is dropped of from C# 7.0
//public readonly struct  ReadonlyPoint
public struct  ReadonlyPoint
{
  public int X {get;}
  public int Y {get;}
  public ReadonlyPoint(int x, int y)
  {
    X = x;
    Y = y;
  }
}


  public static void Main(string[] args)
  {
    {
      var p1 = new Point(3,1);
      var p2 = new Point(3,4);
      var distance1 = p1.DistanceTo(p2);
      var distance2 = Point.DistanceBetween(p1, p2);
      Console.WriteLine($"distance1: {distance1}, distance2: {distance2}");
    }
    Console.WriteLine();

    {
    }
    Console.WriteLine();
  }
}