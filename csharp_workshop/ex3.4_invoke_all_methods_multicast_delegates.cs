using System;
using System.IO; // File class
using System.Text;
using static System.Math;
using System.Collections.Generic;

public class Test
{
// public abstract class MulticastDelegate : Delegate 
// {
//     public sealed override Delegate[] GetInvocationList();
// }

static void LogToConsole(string msg) => Console.WriteLine($"LogToConsole: {msg}");

static void LogToDatabase(string msg)
{
    Console.WriteLine($"LogToDatabase: {msg}");
    throw new ApplicationException("Bad thing happened!");
}

static void LogToFile(string msg) => File.AppendAllText(OutputFile, msg+"\n");

static void InvokeAll(Action<string> logger, string arg)
{
    if (logger == null)
        return;
    var delegateList = logger.GetInvocationList();
    Console.WriteLine($"Found {delegateList.Length} items in the {logger}");
    foreach(var delg in delegateList)
    {
        try
        {
            //var action = delg as Action<string>;
            // if (delg is Action<string> action)
            if (delg is Action<string> action)
            {
                Console.WriteLine($"Invoking '{action.Method.Name}' with '{arg}'");
                action(arg);
            } 
            else
            {
                Console.WriteLine("skipped null delegate");
            }
        }
        catch(Exception e)
        {
            Console.WriteLine($"Error: {e.Message}");
        }
    }
}

  private const string OutputFile = "Exercise3.4.txt";
  public static void Main(string[] args)
  {
    {
        if (File.Exists(OutputFile))
            File.Delete(OutputFile);
        Action<string> logger = LogToConsole;
        InvokeAll(logger, "First call");
        logger += LogToConsole;
        logger += LogToDatabase;
        logger += LogToFile;
        InvokeAll(logger, "Second call");
    }
    Console.WriteLine();

    {

    }
    Console.WriteLine();
  }
}