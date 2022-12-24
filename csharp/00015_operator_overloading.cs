using System;
using System.Net;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

using System.Xml;

using System.Runtime.CompilerServices;
using System.Dynamic;


class test
{
  public struct Note
  {
    int value;
    public Note (int semitonesFromA) { value = semitonesFromA; }

    public static Note operator + (Note x, int semitones)
    {
      return new Note (x.value + semitones);
    }
  }

// Convert to hertz
// public static implicit operator double (Note x)
//                         => 440 * Math.Pow (2, (double) x.value / 12 );

// Convert from hertz (accurate to the nearest semitone)
// public static explicit operator Note (double x)
//                         => new Note ((int) (0.5 + 12 * (Math.Log (x/440) / Math.Log(2) ) ));


  static void Main(string[] args)
  {
    {
      Note b = new Note(2);
      var b2 = b + 2;

      // to switch on when compiling the code:
      // mcs -out:123787.exe -d:DEBUG_FLAG 00015_operator_overloading.cs
      #if DEBUG_FLAG
      Console.WriteLine("checking debug mode");
      #endif
    }

    {
      Console.WriteLine();
    }

    {
      Console.WriteLine();
    }

    Console.WriteLine();
  }

}
