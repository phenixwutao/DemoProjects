using System;
using System.Text;

public interface IWorker
{
  void Work();
}

public interface IFlyer
{
  void Fly();
}

public class Drone : IWorker, IFlyer
{
  public void Work(){ Console.WriteLine("Drone is Working");}
  public void Fly(){ Console.WriteLine("Drone is Flying");}
}

public interface IDone : IWorker, IFlyer
{
}

public class Ant : IWorker
{
  public void Work()
  {
    Console.WriteLine("Ant is working hard");
  }
}

public class FlyingAnt : Ant, IFlyer
{
  public void Fly()
  {
    Console.WriteLine("Ant is flying");
  }
}

public class Robot : IWorker
{
  public void Work()
  {
    Console.WriteLine("Robot is working hard");    
  }
}

  public abstract class Human : IWorker
  {
    public string Name {get;}
    public int Age {get;}
    public double Height {get;}
    public double Weight {get;}
    protected Human(string name, int age, double weight, double height)
    {
      Name = name;
      Age = age;
      Height = height;
      Weight = weight;
    }
    
    public abstract void Work();
    public override string ToString()
    {
      return $"{nameof(Name)}: {Name}," +
        $"{nameof(Age)}: {Age}," +
        $"{nameof(Height)}: {Height}," +
        $"{nameof(Weight)}: {Weight},";
    }
  }

  public class Teacher : Human
  {
    public Teacher(string name, int age, double weight, double height) : base(name, age, weight, height)
    {}

    public override void Work()
    {
      Console.WriteLine("A teacher is teaching");
    }
  }

  public class Mail
  {
    public string Message {get;}
    public string Address {get;}
    public Mail(string mess, string addr)
    {
      Message = mess;
      Address = addr;
    }
  }

  public class Mailman : Human
  {
    public Mailman(string name, int age, double weight, double height) : base(name, age, weight, height)
    {}

    public void DeliverMail(Mail mail)
    {}

    // demo polymorphsim
    public override void Work()
    {
      Console.WriteLine("A mailman is delivering mails");      
    }
  }


class test
{
  public static void Main(string[] args)
  {
    {
      IWorker human = new Mailman("Thomas", 29, 78.5f, 190.11f);
      IWorker ant = new Ant();
      IWorker robot = new Robot();
      IWorker[] workers = {human, ant, robot};
      foreach (var worker in workers)
      {
      worker.Work();
      }
    }

    {
    }

    Console.WriteLine();
  }
}

