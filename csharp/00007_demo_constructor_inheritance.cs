using System;
using System.Text;

class test
{
  public class Baseclass
  {
    public int X;
    public Baseclass () { }
    public Baseclass (int x) { this.X = x; }
  }

  public class Subclass : Baseclass 
  { 
    Subclass(int x) : base(x) {}
  }

  public class Stack
  {
    public int position;
    object[] data = new object[10];

    public void Push (object obj) { data[position++] = obj; }
    public object Pop() { return data[--position]; }
  }

  public class Panda
  {
    public string Name;
    public override string ToString() => Name;
  }

  public enum BorderSide { Left, Right, Top, Bottom }

  static bool IsFlagDefined (Enum e)
  {
    decimal d;
    return !decimal.TryParse(e.ToString(), out d);
  }
  [Flags]
  public enum BorderSides { Left=1, Right=2, Top=4, Bottom=8 }

  static void Main()
  {
    {
      Stack stack = new Stack();
      Console.WriteLine (stack.GetType().Name);
      Console.WriteLine (typeof (Stack).Name);
      Console.WriteLine (stack.GetType() == typeof(Stack)); // True
      Console.WriteLine (stack.position.GetType().Name); // Int32
      Console.WriteLine (stack.position.GetType().FullName); // System.Int32
    }

    {
      Panda chi = new Panda{ Name = "chi"};
      Console.WriteLine("panda's name is: " + chi.ToString());
      BorderSide side = (BorderSide) 12345;
      Console.WriteLine ((typeof (BorderSide)));
      Console.WriteLine (Enum.IsDefined (typeof (BorderSide), side)); // False
      for (int i = 0; i <= 16; i++)
      {
        BorderSides eside = (BorderSides)i;
        Console.WriteLine (i.ToString() + " : " + IsFlagDefined (eside) + " " + eside);
      }
    }


    Console.WriteLine();
  }
}
