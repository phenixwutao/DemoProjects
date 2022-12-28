using System;
using System.Text;
using static System.Math;

public class Test
{
  public static class Comparator
  {
    public static bool IsFirstBigger1(IComparable first, IComparable second)
    {
      return first.CompareTo(second) > 0;
    }

    // where is generic conatraint
    public static bool IsFirstBigger2<T>(T first, T second) where T : IComparable
    {
    return first.CompareTo(second) > 0;
    }

    public static IComparable Max1(IComparable first, IComparable second)
    {
      return first.CompareTo(second) > 0 ? first : second;
    }

    public static T Max2<T>(T first, T second) where T : IComparable
    {
      return first.CompareTo(second) > 0 ? first : second;
    }
  }

  // enum is value type
  public enum Gender
  {
    Male, Female, Other
  }

  public static void Main(string[] args)
  {
    int max1 = (int)Comparator.Max1(3,-4);
    int max2 = Comparator.Max2(3,-4);
    Console.WriteLine("max1 {0}, max2 {1}", max1, max2);

    Gender gen = Gender.Male;
    Gender gen1 = gen;
    gen1 = Gender.Female;
    Console.WriteLine("gen {0}, gen1 {1}", gen, gen1);
  }
}