using System;
using System.IO; // File class
using System.Text;
using static System.Math;
using System.Collections.Generic;

public class AlarmClock {
    public event EventHandler WakeUp = delegate {};
    public event EventHandler<DateTime> Ticked = delegate {};

    protected void onWakeUp()
    {
        WakeUp.Invoke(this, EventArgs.Empty);
    }
    public DateTime AlarmTime {get; set;}
    public DateTime ClockTime {get; set;}

    public void Start()
    {
        const int MinutesInADay = 60*24;
        for(var i = 0; i < MinutesInADay; i++)
        {
            ClockTime = ClockTime.AddMinutes(1);
            Ticked.Invoke(this, ClockTime);

            var timeRemaining = ClockTime.Subtract(AlarmTime).TotalMinutes;
            if (IsTimeToWakeUp(timeRemaining))
            {
                onWakeUp();
                break;
            }
        }

    }


    private static bool IsTimeToWakeUp(double timeRemaining) 
                => timeRemaining >= -1.0 && timeRemaining <= 1.0;

}

public class Test
{
    static void ClockWakeUp(object sender, EventArgs arg)
    {
        Console.WriteLine();
        Console.WriteLine("Wake up");
    }

    static void ClockTicked(object sender, DateTime e) => Console.Write($"{e:t}...");

  public static void Main(string[] args)
  {
    {
        var clock = new AlarmClock();
        clock.Ticked += ClockTicked;
        clock.WakeUp += ClockWakeUp;

        clock.ClockTime = DateTime.Now;
        clock.AlarmTime = DateTime.Now.AddMinutes(120);
        Console.WriteLine($"ClockTime={clock.ClockTime:t}");
        Console.WriteLine($"AlarmTime={clock.AlarmTime:t}");
        clock.Start();
        Console.WriteLine("Start now");
        // To prevent memory leaks, always try to pair up each += call with 
        // a corresponding -= operator.
    }
    Console.WriteLine();

    {

    }
    Console.WriteLine();
  }
}