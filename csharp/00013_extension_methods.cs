using System;
using System.Net;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

  public static class StringHelper
  {
    // static method in static class with first parameter of data type
    public static bool IsCapitalized (this string s)
    {
      if (string.IsNullOrEmpty(s)) return false;
      return char.IsUpper (s[0]);
    }
    
    public static string Pluralize (this string s)
    {
      return s+"s";
    }

    public static string Capitalize (this string s)
    {
      return s.ToUpper();
    }
  }

///
// 03:45 24/Dec/2022 the ceiling was leaking.
// I have reported before, it is never fixed.

class test
{

  static void Main(string[] args)
  {
    {
      Console.WriteLine ("Perth".IsCapitalized());
      Console.WriteLine (StringHelper.IsCapitalized ("Perth"));
      string x = "sausage".Pluralize().Capitalize();
      string y = StringHelper.Capitalize (StringHelper.Pluralize ("sausage"));
      string x2 = "sausage".Pluralize();
      string x3 = "sausage".Capitalize();

      Console.WriteLine(x + " , " + y);
      Console.WriteLine(x2 + " , " + x3);
    }

    {
      // anonymous types
      var dude = new {Name = "Bob", Age = 23};
    }

    Console.WriteLine();
  }

}
