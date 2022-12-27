using System;
using System.Text;


class test
{
  public abstract class Human
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

  public static void Run()
        {
            DemoInheritance();
            DemoNoPolymorphism();
            DemoPolymorphism();
        }

        private static void DemoInheritance()
        {
            var mailman = new Mailman("Thomas", 29, 78.5f, 190.11f);
            var mail = new Mail("Hello", "Somewhere far far way");
            mailman.DeliverMail(mail);
        }

        private static void DemoNoPolymorphism()
        {
            Mailman mailman = new Mailman("Thomas", 29, 78.5f, 190.11f);
            Teacher teacher = new Teacher("Gareth", 35, 100.5f, 186.49f);
            Human[] humans = { mailman, teacher };
            foreach (var human in humans)
            {
                Type humanType = human.GetType();
                if (humanType == typeof(Mailman))
                {
                    Console.WriteLine("Mailman is working...");
                }
                else
                {
                    Console.WriteLine("Teaching");
                }
            }
        }

        private static void DemoPolymorphism()
        {
            Mailman mailman = new Mailman("Thomas", 29, 78.5f, 190.11f);
            Teacher teacher = new Teacher("Gareth", 35, 100.5f, 186.49f);
            // Specialized types can be stored as their generalized forms.
            Human[] humans = { mailman, teacher };
            foreach (var human in humans)
            {
                human.Work();
            }

            foreach (var human in humans)
            {
                Console.WriteLine(human);
            }
        }

  public static void Main(string[] args)
  {
    {
      Run();
    }

    {
    }

    Console.WriteLine();
  }
}

