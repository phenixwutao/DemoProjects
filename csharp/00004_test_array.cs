// C# code chapter 2

using System;

public struct Point
{
  public int x;
  public int y;
}

public class PointC
{
  public int x;
  public int y;
}

struct Deal
{
  int ID;
}

class Test
{
  public class Dude
  {
    public string Name;
    public Dude (string n) { Name = n; }
  }

  static void Main()
  {
    {
      int[] a = new int[100]; // default values are initialised to zeros
      Console.WriteLine("a[13]={0}",a[13]);
    }

    // test value type and reference type
    {
      // struct Point is value type
      Point[] a = new Point[10];
      int x = a[3].x;
      Console.WriteLine("x={0}",x);

      // class PointC is reference type
      PointC[] b = new PointC[10];
      for(var i = 0; i < b.Length; ++i)
      {
        b[i] = new PointC();
        var xb = b[i].x;
        Console.WriteLine("xb={0}",xb);
      }

      // an array is always reference type
      int[] xarray = null;
    }

    // test index
    {
      char[] vowels = new char[] {'a','e','i','o','u'};
      //char lastElement = vowels[^1];  // C# 10.0
      //char secondToLast = vowels[^2]; // C# 10.0
      char lastElement = vowels[vowels.Length-1];
      char secondToLast = vowels[vowels.Length-2];
      Console.WriteLine("lastElement {0}, secondToLast {1}",lastElement, secondToLast);

      // test ranges [m..2] works for C# 10.0
      // char[] part1 = vowels [..2];
      // char[] part2 = vowels [2..];
      // Console.WriteLine("part1 {0}, part2 {1}",part1, part2);

      // char[] lastTwo = vowels [^2..]; // 'o', 'u'
      // Range firstTwoRange = 0..2;
      // char[] firstTwo = vowels [firstTwoRange]; // 'a', 'e'
    }

    // test multi-dimentional array
    {
      int[,] matric = new int[3,3];
      for(int i = 0; i < matric.GetLength(0); ++i)
        for(int j = 0; j < matric.GetLength(1); ++j)
          matric[i,j] = i*3 + j;

      int [,] mm2 = new int[,] {{1,2,3},{4,5,6},{7,8,9}};

      // Jagged array
      int[][] mm3 = new int[3][];
      for(int i = 0; i < mm3.Length; ++i)
      {
        mm3[i] = new int[3];
        for(int j = 0; j < mm3[i].Length; ++j)
        {
          mm3[i][j] = i*3 +j;
        }
      }

      int[][] mm4 = new int [][]
      {
        new int[] {1,2,3},
        new int[] {4,5,6},
        new int[] {7,8,9}
      };

      // simplified initialization
      char[] vw2 = {'a','e','i','o','u'};
      int[,] rectangularMatrix = {
        {1,2,3}, {4,5,6}, {7,8,9}
      };

      int [][] jaggedMatrix = {
        new int[] {1,2,3},
        new int[] {4,5,6},
        new int[] {7,8,9}
      };

      var i3 = 3; // i is implicitly of type int
      var s3 = "sausage"; // s is implicitly of type string

      var rectMatrix = new int[,] // rectMatrix is implicitly of type int[,]
                          {
                            {0,1,2},
                            {3,4,5},
                            {6,7,8}
                          };

      var jaggedMat = new int[][] // jaggedMat is implicitly of type int[][]
                      {
                        new int[] {0,1,2},
                        new int[] {3,4,5},
                        new int[] {6,7,8}
                      };
    }

    Console.WriteLine();
  }

}
