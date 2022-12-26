using System;
using System.Net;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

using System.Xml;

using System.Runtime.CompilerServices;
using System.Dynamic;

using System.Globalization;


class test
{

  static void Main(string[] args)
  {
    {
      Console.WriteLine("---------------- char");
      char c = 'A';
      char newLine = '\n';
      Console.WriteLine (System.Char.ToUpper ('c')); // C
      Console.WriteLine (char.IsWhiteSpace ('\t')); // True for All separators plus \n, \r, \t, \f, and \v
      Console.WriteLine (char.ToUpper ('i', CultureInfo.InvariantCulture));
    }

    {
      Console.WriteLine("---------------- string");
      string s1 = "Hello";
      string s2 = "First Line\r\nSecond Line";
      string s3 = @"\\server\fileshare\helloworld.cs";  // raw string
      Console.WriteLine("s1 " + s1);
      Console.WriteLine("s2 " + s2);
      Console.WriteLine("s3 " + s3);
      Console.Write (new string ('*', 10));
      char[] ca = "Hello".ToCharArray();
      string s4 = new string (ca);
      Console.WriteLine("s4 " + s4);

      string s5 = "abcdef";
      var check = s5.StartsWith ("aBc", StringComparison.InvariantCultureIgnoreCase);
      Console.WriteLine(check);
      Console.WriteLine ("abcde abcde".IndexOf ("CD", 6,
                          StringComparison.CurrentCultureIgnoreCase)); // 8
      Console.WriteLine ("ab,cd ef".IndexOfAny (new char[] {' ', ','} )); // 2
      Console.WriteLine ("pas5w0rd".IndexOfAny ("0123456789".ToCharArray() )); // 3
      Console.WriteLine ("12345".PadLeft (9, '*')); // ****12345
      Console.WriteLine ("12345".PadLeft (9)); // 12345
      Console.WriteLine (" abc \t\r\n ".Trim());
      Console.WriteLine (" abc \t\r\n ".Trim().Length); // 3

      string[] words = "The quick brown fox".Split();
      foreach (string word in words)
        Console.Write (word + "|"); // The|quick|brown|fox|
      Console.WriteLine();

      string composite = "It's {0} degrees in {1} on this {2} morning";
      string s6 = string.Format (composite, 35, "Perth", DateTime.Now.DayOfWeek);
      Console.WriteLine(composite);
      Console.WriteLine(s6);

      string s7 = $"It's hot this {DateTime.Now.DayOfWeek} morning";
      Console.WriteLine(s7);
    }

    {
      // name format pad right, limit pad left (page 262 format details)
      Console.WriteLine("------------- format");
      NumberFormatInfo f = new NumberFormatInfo();
      f.CurrencySymbol = "$";
      string composite = "Name={0,-20} Credit Limit={1,15:C}";
      Console.WriteLine (string.Format (composite, "Mary", 500));
      Console.WriteLine (string.Format (composite, "Katie", -1500));
      Console.WriteLine (string.Format (composite, "Elizabeth", 20000));
      Console.WriteLine();
      byte[] utf8Bytes = System.Text.Encoding.UTF8.GetBytes ("0123456789");
      byte[] utf16Bytes = System.Text.Encoding.Unicode.GetBytes ("0123456789");
      byte[] utf32Bytes = System.Text.Encoding.UTF32.GetBytes ("0123456789");
      Console.WriteLine(utf8Bytes.Length);
      Console.WriteLine(utf16Bytes.Length);
      Console.WriteLine(utf32Bytes.Length);

      TimeSpan nearlyTenDays = TimeSpan.FromDays(10) - TimeSpan.FromSeconds(1);
      Console.WriteLine (nearlyTenDays.Days); // 9
      Console.WriteLine (nearlyTenDays.Hours); // 23
      Console.WriteLine (nearlyTenDays.Minutes); // 59
      Console.WriteLine (nearlyTenDays.Seconds); // 59
      Console.WriteLine (nearlyTenDays.Milliseconds); // 0

      DateTime d = new DateTime (5767, 1, 1,
                                new System.Globalization.HebrewCalendar());
      Console.WriteLine (d); // 12/12/2006 12:00:00 AM

      Console.WriteLine (DateTime.Now); // 11/11/2015 1:23:45 PM
      Console.WriteLine (DateTimeOffset.Now); // 11/11/2015 1:23:45 PM -06:00

      Console.WriteLine("------------- DateTime");
      DateTime dt = new DateTime (2000, 2, 3, 10, 20, 30);
      Console.WriteLine (dt.Year); // 2000
      Console.WriteLine (dt.Month); // 2
      Console.WriteLine (dt.Day); // 3
      Console.WriteLine (dt.DayOfWeek); // Thursday
      Console.WriteLine (dt.DayOfYear); // 34
      Console.WriteLine (dt.Hour); // 10
      Console.WriteLine (dt.Minute); // 20
      Console.WriteLine (dt.Second); // 30
      Console.WriteLine (dt.Millisecond); // 0
      Console.WriteLine (dt.Ticks); // 630851700300000000
      Console.WriteLine (dt.TimeOfDay); // 10:20:30 (returns a TimeSpan)

      DateTime dt1 = DateTime.Now;
      Console.WriteLine(dt1.ToString());
      Console.WriteLine(dt1.ToLongDateString());
      Console.WriteLine(dt1.ToShortDateString());
    }

    {
      DateTime dt1 = new DateTime (2000, 1, 1, 10, 20, 30, DateTimeKind.Local);
      DateTime dt2 = new DateTime (2000, 1, 1, 10, 20, 30, DateTimeKind.Utc);
      Console.WriteLine (dt1 == dt2); // True
      DateTime local = DateTime.Now;
      DateTime utc = local.ToUniversalTime();
      Console.WriteLine (local);
      Console.WriteLine (utc);
      Console.WriteLine (local == utc); // False

      TimeZone zone = TimeZone.CurrentTimeZone;
      Console.WriteLine (zone.StandardName); // Pacific Standard Time
      Console.WriteLine (zone.DaylightName); // Pacific Daylight Time

    }

    Console.WriteLine();
  }

}
