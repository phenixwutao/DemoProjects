using System;
using System.Net;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;


class test
{
  static (string,int) GetPerson() => ("Bow", 25);

  static (string Name, int Age) GetNamePerson() => ("Jogn", 26);

  static void Main(string[] args)
  {
    {
      var developers = ("Bob", 23);
      Console.WriteLine(developers.Item1); // Bob
      Console.WriteLine(developers.Item2); // 23
      var joe = developers;
      Console.WriteLine(joe);

      var person = GetPerson();
      Console.WriteLine(person);
    }

    {
      // naming tuple elements
      var tuple = (Name:"Bob", Age:23);
      Console.WriteLine (tuple.Name); // Bob
      Console.WriteLine (tuple.Age); // 23

      var tuple2 = GetNamePerson();
      Console.WriteLine (tuple2.Name);
      Console.WriteLine (tuple2.Age);
      Console.WriteLine (tuple2.Item1);
      Console.WriteLine (tuple2.Item2);
    }


    {
      ValueTuple<string,int> bob1 = ValueTuple.Create ("Bob", 23);
      var bob = ("Bob", 23);
      // (string name, int age) = bob;
    }

    {
      // tuple comparison
      var t1 = ("one", 1);
      var t2 = ("one", 1);
      Console.WriteLine (t1.Equals (t2)); // True
    }

    {
      // system tuple generics
      Tuple<string,int> t = Tuple.Create ("Rob", 33); // Factory method
      Console.WriteLine (t.Item1); // Rob
      Console.WriteLine (t.Item2); // 33
    }
    Console.WriteLine();
  }

}
