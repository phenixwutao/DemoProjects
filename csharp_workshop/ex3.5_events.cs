using System;
using System.IO; // File class
using System.Text;
using static System.Math;
using System.Collections.Generic;

// EventHandler or EventHandler<> generics
// old legacy code: public delegate void EventHandler(object sender, EventArgs e)
// Generics:  public delegate void EventHandler<T>(object sender, T e)

public class MouseClickedEventArgs
{
    public MouseClickedEventArgs(int clicks)
    {
        Clicks = clicks;
    }

    public int Clicks {get;}
}

public class MouseClickPublisher
{
    public event EventHandler<MouseClickedEventArgs> MouseClicked = delegate { };

    protected virtual void OnMouseClicked(MouseClickedEventArgs e)
    {
        var evt = MouseClicked;
        evt?.Invoke(this, e);
    }

    private void TrackMouseClicks()
    {
        OnMouseClicked(new MouseClickedEventArgs(2));
    }
}

public class MouseSingleClickPublisher : MouseClickPublisher
{
    protected override void OnMouseClicked(MouseClickedEventArgs e)
    {
        if (e.Clicks == 1)
        {
            OnMouseClicked(e);
        }
    }   
}

public class Test
{

  public static void Main(string[] args)
  {
    {
    }
    Console.WriteLine();

    {

    }
    Console.WriteLine();
  }
}