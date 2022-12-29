using System;
using System.IO; // File class
using System.Text;
using static System.Math;
using System.Collections.Generic;

public class CashMachine{
    private readonly Action<string> _logger;
    public CashMachine(Action<string> logger)
    {
        _logger = logger;
    }
    private void Log(string message) => _logger?.Invoke(message);

    public void VerifyPin(string pin) => Log($"VerifyPin called PIN={pin}");
    public void ShowBalance() => Log($"ShowBalance called: balance =999");
}

public class Test
{
    private const string OutputFile = "activity.txt";
    static void LogToConsole(string message) => Console.WriteLine("LogToConsole: "+message);
    static void LogToFile(string message) => File.AppendAllText(OutputFile, "LogToFile: "+message+"\n");

  public static void Main(string[] args)
  {
    {
        if (File.Exists(OutputFile))
        {
            File.Delete(OutputFile);
        }
        Action<string> logger = LogToConsole;
        logger += LogToFile;
        CashMachine cashm = new CashMachine(logger);
        string pin = "1232";
        cashm.VerifyPin(pin);
        cashm.ShowBalance();
    }
    Console.WriteLine();

    {

    }
    Console.WriteLine();
  }
}