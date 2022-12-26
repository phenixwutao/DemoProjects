using System;
using System.Text;

class test
{

  public class Person
  {
    public Person() { }
    public Person(string name, int age)
    {
      Name = name;
      Age = age;
    }

    public string Name { get; set; }

    public int Age { get; set; }

    public void GetInfo()
    {
      Console.WriteLine($"Name: {Name} – IsChild? {IsChild()}");
    }

    public bool IsChild()
    {
      return Age < 12;
    }
  }


struct GoldenRetriever
{
  public string Name { get; set; }
}

class BorderCollie
{
  public string Name { get; set; }
}

class Bernese
{
  public string Name { get; set; }

  public override bool Equals(object obj)
  {
    if (obj is Bernese borderCollie && obj != null)
    {
      return this.Name == borderCollie.Name;
    }
    return false;
  }
}

  static void Main(string[] args)
  {
    {
      Person per1 = new Person() {Name = "Tom", Age=30};

      var now = DateTime.Now;
      var now2 = DateTime.UtcNow;
      Console.WriteLine(now);
      Console.WriteLine(now2);
    }

    {
    Console.WriteLine("Are the local and utc dates equal? {0}", DateTime.Now.Date == DateTime.UtcNow.Date);
    Console.WriteLine("\nIf the dates are equal, does it mean that there's no TimeSpan interval between them? {0}",
      (DateTime.Now.Date - DateTime.UtcNow.Date) == TimeSpan.Zero);

    DateTime localTime = DateTime.Now;
    DateTime utcTime = DateTime.UtcNow;
    TimeSpan interval = (localTime - utcTime);
    Console.WriteLine("\nDifference between the {0} Time and {1} Time:{2}:{3} hours",
                      localTime.Kind.ToString(),
                      utcTime.Kind.ToString(),
                      interval.Hours,
                      interval.Minutes);
    Console.WriteLine("\nIf we jump two days to the future on {0} we'll be on {1}",
      new DateTime(2020, 12, 31).ToShortDateString(),
      new DateTime(2020, 12, 31).AddDays(2).ToShortDateString());      
    }

    // formatting dates
    {
      Console.WriteLine("formatting date");
      var frenchDate = new DateTime(2008, 3, 1, 7, 0, 0);
      Console.WriteLine("French date: " + 
        frenchDate.ToString(System.Globalization.CultureInfo.CreateSpecificCulture("fr-FR")));
      // Displays 01/03/2008 07:00:00

      var usDate = new DateTime(2008, 3, 1, 7, 0, 0);
      Console.WriteLine("US date: " + 
        usDate.ToString(System.Globalization.CultureInfo.CreateSpecificCulture("en-US")));
      // For en-US culture, displays 3/1/2008 7:00:00 AM

      var date1 = new DateTime(2008, 3, 1, 7, 0, 0);
      Console.WriteLine(date1.ToString("yyyyMMddTHH:mm:ss"));
    }

    {
      var aGolden = new GoldenRetriever() { Name = "Aspen" };
      var anotherGolden = new GoldenRetriever() { Name = "Aspen" };

      var aBorder = new BorderCollie() { Name = "Aspen" };
      var anotherBorder = new BorderCollie() { Name = "Aspen" };

      var aBernese = new Bernese() { Name = "Aspen" };
      var anotherBernese = new Bernese() { Name = "Aspen" }; 

      var goldenComparison = aGolden.Equals(anotherGolden) ? 
            "These Golden Retrievers have the same name." : "These Goldens have different names.";
      var borderComparison = aBorder.Equals(anotherBorder) ? 
            "These Border Collies have the same name." : "These Border Collies have different names.";
      var berneseComparison = aBernese.Equals(anotherBernese) ? 
            "These Bernese dogs have the same name." : "These Bernese dogs have different names.";

      Console.WriteLine(goldenComparison);
      Console.WriteLine(borderComparison);
      Console.WriteLine(berneseComparison); 
    }
    Console.WriteLine();
  }
}

