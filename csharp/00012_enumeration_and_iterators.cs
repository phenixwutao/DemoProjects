using System;
using System.Net;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

// Enumeration and Iterators page 167

///
// 03:45 24/Dec/2022 the ceiling was leaking.
// I have reported before, it is never fixed.

class test
{

  static void Main(string[] args)
  {
    {
      foreach (int fib in Fibs(10))
        Console.Write (fib + " ");
      Console.WriteLine();
    }

    {
      foreach (var s in EnumerableBreak(true))
        Console.Write (s + " ");
      Console.WriteLine();

    }

    {
      foreach (int fib in EvenNumbersOnly (Fibs(10)))
        Console.Write (fib + " ");
      Console.WriteLine();
    }

    {
      // Nullable type and operators: ?   ??   ?.
      int? kk = null;
      Console.WriteLine (kk == null);

      int? x = null;
      int y = x ?? 5; // Null coalescing operator: if x is null, y is 5, otherwise y is x
      Console.WriteLine(y);

      System.Text.StringBuilder sb = null;
      int? length = sb?.ToString().Length; // null-conditional operator
      Console.WriteLine(length);
    }
    Console.WriteLine();
  }

  static IEnumerable<int> Fibs (int fibCount)
  {
    for (int i = 0, prevFib = 1, curFib = 1; i < fibCount; i++)
    {
      yield return prevFib; // next element yield from this enumerator
      int newFib = prevFib+curFib;
      prevFib = curFib;
      curFib = newFib;
    }
  }


  static IEnumerable<string> EnumerableBreak(bool breakEarly)
  {
    yield return "One";
    yield return "Two";
    if (breakEarly)
      yield break;
    yield return "Three";
  }

  static IEnumerable<int> EvenNumbersOnly (IEnumerable<int> sequence)
  {
    foreach (int x in sequence)
      if ((x % 2) == 0)
        yield return x;
  }
}
