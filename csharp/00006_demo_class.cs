using System;
using System.Text;

class test
{
  int Cube (int value) => value * value * value;

  public void WriteCubes()
  {
    Console.WriteLine (Cube (3));
    Console.WriteLine (Cube (4));
    Console.WriteLine (Cube (5));
  }

  public class Panda
  {
    string name;

    // constructor
    public Panda(string n) => name = n;
  }

  public class Wine 
  {
    public decimal Price;
    public int Year;

    public Wine(decimal price) { Price = price; }
    public Wine(decimal price, int year) : this(price) {Year = year;}
    public Wine(decimal price, DateTime year) : this(price, year.Year) {}
  }

  public class Rectangle
  {
    public readonly float Width, Height;

    public Rectangle (float width, float height)
    {
      Width = width;
      Height = height;
    }

    public void Deconstruct (out float width, out float height)
    {
      width = Width;
      height = Height;
    }
  }

  public class Bunny
  {
    public string Name;
    public bool LikesCarrots;
    public bool LikesHumans;
    public Bunny () {}
    public Bunny (string n) { Name = n; }
  }

  // Actor: Eva Green, María Valverde, Imogen Poots

  public class Stock
  {
    public decimal currentPrice;
    public decimal shareowned;

    // expression-bodied property
    public decimal Worth
    {
      get => currentPrice * shareowned;
      set => shareowned = value / currentPrice;
    }

    // equivalent old style properties
    public decimal Worth2
    {
      get { return currentPrice * shareowned; }
      set { shareowned = value / currentPrice; }
    }

    public decimal CurrentPrice
    {
      get => currentPrice;
      set => currentPrice = value;
    }

    // Finalizer is like C++ destructor
    ~Stock() => Console.WriteLine("Finalizing Stock");
  }

  class Sentence
  {
    string[] words = "The quick brown fox".Split();

    // Implementing an indexer
    public string this [int wordNum] // indexer
    {
      get { return words [wordNum]; }
      set { words [wordNum] = value; }
    }
  }

  public abstract class Asset
  {
    public string Name;
    public virtual decimal Liability => 0;
    public abstract decimal NetValue {get;}
  }

  public class MyStock : Asset // inherits from Asset
  {
    public long SharesOwned;
    public decimal CurrentPrice;
    public override decimal NetValue => CurrentPrice * SharesOwned;
  }

  public class MyHouse : Asset // inherits from Asset
  {
    public decimal Mortgage;
    public sealed override decimal Liability => base.Liability + Mortgage; // same as {get { return Mortgage;}}
    public override decimal NetValue => Mortgage;
  }

  public static void Display (Asset asset)
  {
    System.Console.WriteLine (asset.Name);
  }

  // new is not operator here, new is modifier
  public class A { public int Counter = 1; }
  public class B : A { public new int Counter = 2; }

  // override versus new hider
  public class BaseClass
  {
    public virtual void Foo() { Console.WriteLine ("BaseClass.Foo"); }
  }

  public class Overrider : BaseClass
  {
    public override sealed void Foo() { Console.WriteLine ("Overrider.Foo"); }
  }

  public sealed class Overrider2 : Overrider
  {
    // cannot override Foo because parent class method is sealed, (final)
    //public override void Foo() { Console.WriteLine ("Overrider2.Foo"); }    
  }

  // class Overrider2 is sealed (final)
  // public class Overrider3 : Overrider2
  // {}

  public class Hider : BaseClass
  {
    public new void Foo() { Console.WriteLine ("Hider.Foo"); }
  }

  static void Main()
  {
    {
      var rect = new Rectangle (3, 4);
      // float width;
      // float height;
      rect.Deconstruct(out var width, out var height); // Deconstruction is valid for C# 7.0 or higher
      Console.WriteLine (width + " " + height); // 3 4
    }

    {
      Bunny b1 = new Bunny { Name = "Bo", LikesCarrots = true, LikesHumans = false};
      Bunny b2 = new Bunny("Bo") {LikesCarrots = true, LikesHumans = false};
    }

    {
      Sentence s = new Sentence();
      Console.WriteLine (s[3]); // fox
      s[3] = "kangaroo";
      Console.WriteLine (s[3]); // kangaroo
    }

    {
      Stock a = new Stock();
      a.CurrentPrice = 35.5m;
      Console.WriteLine("test nameof operator: nameof(a) " + nameof(a) + "  nameof(a.CurrentPrice): " + nameof(a.CurrentPrice));
    }

    {
      MyStock msft = new MyStock { Name="MSFT", SharesOwned=1000 };
      MyHouse mansion = new MyHouse { Name="Mansion", Mortgage=250000 };
      Display(msft);
      Display(mansion);
      Asset a = mansion;
      MyStock s = a as MyStock;
      if (s != null)
        Console.WriteLine ("SharesOwned as {0}", s.SharesOwned);

      if (a is MyStock) {
        var s1 = (MyStock) a;
        Console.WriteLine ("SharesOwned is {0}", s1.SharesOwned);
      }

      // C# 7.0 or higher
      // if (a is Stock s2 && s2.SharesOwned > 100000)
      //   Console.WriteLine ("Wealthy");

      Asset aa = mansion;
      Console.WriteLine("aa Liability: {0}", aa.Liability);
      Console.WriteLine("mansion Liability: {0}", mansion.Liability);
    }

    {
      Overrider over = new Overrider();
      BaseClass b1 = over;
      over.Foo(); // Overrider.Foo
      b1.Foo(); // Overrider.Foo

      Hider h = new Hider();
      BaseClass b2 = h;
      h.Foo(); // Hider.Foo
      b2.Foo(); // BaseClass.Foo it is not polymorphism
    }
    Console.WriteLine();
  }
}
