using System;
using System.Text;
using static System.Math;

class Test
{
  public interface IReader
  {
    string Read(string filePath);
  }

  public class Reader :IReader
  {
    public string Read(string filePath)
    {
      return "";
    }
  }

  public interface IWriter
  {
    void Write(string filePath, string content);
  }

  public class Writer : IWriter
  {
    public void Write(string filePath, string content)
    {}
  }

  public class File {
    private readonly IReader _reader;
    private readonly IWriter _writer;
    public File(IReader reader, IWriter writer)
    {
      _reader = reader;
      _writer = writer;
    }

    public virtual string Read(string filePath) => _reader.Read(filePath);
    public virtual void Write(string filePath, string content) => _writer.Write(filePath, content);

  }

  public class Car
  {
    public object Body {get; set;}
    public virtual void Move(){}
  }

  // child class should support all public behavior
  public class WreckCar : Car
  {
    public override void Move()
    {
      Console.WriteLine(Math.PI);
      Console.WriteLine(PI);
      Console.WriteLine("Wreck car");
      throw new NotSupportedException("a brokn car cannot start.");
    }
  }

  public static void Main(string[] args)
  {
    {
    }
    
    Console.WriteLine();
  }
}


