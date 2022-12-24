using System;
using System.Net;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

using System.Xml;

using System.Runtime.CompilerServices;
using System.Dynamic;

// abstract class System.Attribute;


public class Person
{
  public string firstName;
  public string SurName;
}

public class Duck : DynamicObject
{
  public override bool TryInvokeMember(InvokeMemberBinder binder, 
                                object[] args, out object result)
  {
    Console.WriteLine (binder.Name + " method was called");
    result = null;
    return true;
  }
}

// language binding:
//static dynamic Mean (dynamic x, dynamic y) => (x + y) / 2;

class test
{
  //-----------------------------------------------
  // Caller info attributes are useful for logging
  //-----------------------------------------------
  static void FooCallerInfo (
  [CallerMemberName] string memberName = null,
  [CallerFilePath] string filePath = null,
  [CallerLineNumber] int lineNumber = 0)
  {
    Console.WriteLine (memberName);
    Console.WriteLine (filePath);
    Console.WriteLine (lineNumber);
  }

  [ObsoleteAttribute]
  public class NotUsed {}

  [Obsolete]
  public class NotUsed2 {}

  public static int sqr(int x) { return x*x; }

  // [XmlElement("Customer", Namespace="http://oreilly.com")]
  // public class CustomerEntity {}

  static void Main(string[] args)
  {
    {
      FooCallerInfo();
    }

    {
      // dynamic binding
      dynamic d = new Person();
      d.firstName = "Tracy";
      d.SurName = "Dow";

      dynamic d2 = new Duck();
      d2.Quack();
      d2.Waddle();
    }


    {
      // int x=3, y=4;
      // Console.WriteLine(Mean(x,y));

      //Console.WriteLine(typeof (dynamic) == typeof (object));
      Console.WriteLine(typeof (List<dynamic>) == typeof (List<object>));
      Console.WriteLine(typeof (dynamic[]) == typeof (object[]));
    }

    {
      int i = 7;
      dynamic d = i;
      long j = d; // No cast required (implicit conversion)
      // short k = d;  // throws RuntimeBinderException: cannot convert from int to short
    }

    {
      // var says, “Let the compiler figure out the type.”
      // dynamic says, “Let the runtime figure out the type.”
      dynamic x = "hello"; // Static type is dynamic, runtime type is string
      var y = "hello"; // Static type is string, runtime type is string

      dynamic ii = 3;
      Console.WriteLine(sqr(ii));
    }
    Console.WriteLine();
  }

}
