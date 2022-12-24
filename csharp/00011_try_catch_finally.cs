using System;
using System.Net;
using System.Text;
using System.IO;



class test
{

  static void Main(string[] args)
  {
    {
      try
      {
      byte b = byte.Parse (args[0]);
      Console.WriteLine (b);
      }
      catch (IndexOutOfRangeException ex)
      {
      Console.WriteLine ("Please provide at least one argument");
      }
      catch (FormatException ex)
      {
      Console.WriteLine ("That's not a number!");
      }
      catch (OverflowException ex)
      {
      Console.WriteLine ("You've given me more than a byte!");
      }
      // repeating the catch block by using different when clause
      catch (WebException ex) when (ex.Status == WebExceptionStatus.Timeout)
      {}
      catch (WebException ex) when (ex.Status == WebExceptionStatus.SendFailure)
      {}
    }

    {
      StreamReader reader = null; // In System.IO namespace
      try
      {
        reader = File.OpenText ("00011_try_catch_finally.txt");
        if (reader.EndOfStream) return;
        Console.WriteLine (reader.ReadToEnd());
      }
      finally
      {
        if (reader != null) reader.Dispose();
      }      
    }

    {
      using(StreamReader reader = File.OpenText("00011_try_catch_finally.txt"))
      {
        Console.WriteLine (reader.ReadToEnd());
      }
    }

    {

    }
    Console.WriteLine();
  }

  public string Foo() => throw new NotImplementedException();

  string ProperCase (string value) =>
                value == null ? throw new ArgumentException ("value") :
                value == "" ? "" :
                char.ToUpper (value[0]) + value.Substring (1);
}
