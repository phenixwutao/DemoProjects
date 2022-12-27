using System;
using System.Text;

class Test
{
  public interface IShape
  {
    double Area {get;}
  }

  public class Rectangle : IShape
  {
    private readonly double _width;
    private readonly double _height;
    public double Area {get => _width * _height;}

    public Rectangle(double w, double h)
    {
      _width = w;
      _height = h;
    }
  }

  public class Circle : IShape
  {
    private readonly double _radius;
    public double Area {get => Math.PI* _radius * _radius;}

    public Circle(double r)
    {
      _radius = r;
    }
  }

  public static class Solution
  {
    public static bool IsEnough(double mosaicArea, IShape[] tiles)
    {
      double totalArea = 0;
      foreach(var tile in tiles)
      {
        totalArea += tile.Area;
      }
      const double kTolerance = 0.0001;
      Console.WriteLine($"totalArea {totalArea}, mosaicArea {mosaicArea}, diff {totalArea - mosaicArea}");
      return totalArea - mosaicArea >= -kTolerance;
    }
  }
  public static void Main(string[] args)
  {
    {
      var isEnough1 = Solution.IsEnough(0, new IShape[0]);
      var isEnough2 = Solution.IsEnough(1, new[] {new Rectangle(1,1)} );
      var isEnough3 = Solution.IsEnough(100, new IShape[] {new Circle(5)} );
      var isEnough4 = Solution.IsEnough(5, new IShape[]{
        new Rectangle(1,1), new Circle(1), new Rectangle(1.4,1)
        });

    Console.WriteLine($"isEnough1 = {isEnough1}, "+
      $"isEnough2 = {isEnough2}, "+
      $"isEnough3 = {isEnough3}, "+
      $"isEnough4 = {isEnough4}. ");
    }
    
    Console.WriteLine();
  }
}


