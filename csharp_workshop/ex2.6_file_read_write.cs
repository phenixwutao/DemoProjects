using System;
using System.Text;

class Test
{
  public class Reader
  {
    public string Read(string filePath)
    {
      return "";
    }
  }

  public class Writer
  {
    public void Write(string filePath, string content)
    {}
  }

  public class File {
    private readonly Reader _reader;
    private readonly Writer _writer;
    public File()
    {
      _reader = new Reader();
      _writer = new Writer();
    }
    public File(Reader reader, Writer writer)
    {
      _reader = reader;
      _writer = writer;
    }

    public virtual string Read(string filePath) => _reader.Read(filePath);
    public virtual void Write(string filePath, string content) => _writer.Write(filePath, content);

  }

  public class Car
  {
    public object Body {get; set;};
    public virtual void Move(){}
  }

  // child class should support all public behavior
  public class WreckCar : Car
  {
    public override void Move()
    {
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


