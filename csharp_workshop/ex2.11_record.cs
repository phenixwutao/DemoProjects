using System;
using System.Text;
using static System.Math;

// record is reference type defined from C# 9.0
// a record provides Equals(), GetHashCode() overrides, == and != overrides, and even a
// ToString override, which prints the record itself (all the members and their values).
public struct MovieRecordV1
{
}

public class Dog
{
  public Dog(string name){}
}

public class Human
{
  public Human(string name){}
}

public class Test
{
  public static void Run()
        {
            var dog = new Dog("Sparky");
            var human = new Human("Thomas");
            bool isDogKnown = false;

            var values1 = new ValueTuple<Dog, Human, bool>(dog, human, isDogKnown);
            var values2 = (dog, human, isDogKnown);

            var (d, h, b) = GetDogHumanAndBool();
        }

        public static (Dog, Human, bool) GetDogHumanAndBool()
        {
            var dog = new Dog("Sparky");
            var human = new Human("Thomas");
            bool isDogKnown = false;

            return (dog, human, isDogKnown);
        }

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