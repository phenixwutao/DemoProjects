// See https://aka.ms/new-console-template for more information
using System;
using System.Text;

public class Test
{
  // test record type
public record MovieRecordV1
{
  public string Title { get; }
  public string Director { get; }
  public string Producer { get; }
  public string Description { get; set; }
  public DateTime ReleaseDate { get; }

  public MovieRecordV1(string title, string director, string producer, DateTime releaseDate)
  {
    Title = title;
    Director = director;
    Producer = producer;
    ReleaseDate = releaseDate;
  }
}

public record MovieRecord(string Title, string Director, string Producer, DateTime ReleaseDate)
{
  public string Description { get; set; }
}

private static void DemoRecord()
{
  var movie1 = new MovieRecordV1(
                "Star Wars: Episode I – The Phantom Menace",
                "George Lucas",
                "Rick McCallum",
                new DateTime(1999, 5, 15));
  var movie2 = new MovieRecordV1(
                "Star Wars: Episode I – The Phantom Menace",
                "George Lucas",
                "Rick McCallum",
                new DateTime(1999, 5, 15));
  Console.WriteLine(movie1);
  Console.WriteLine(movie2);
  Console.WriteLine(movie1.Equals(movie2));
  Console.WriteLine(movie1 == movie2);

  // copy record object: perform a shallow copy
  var movie3 = movie2 with { Description = "Records can do that?" };
  movie2.Description = "Changing original";
  Console.WriteLine(movie3);
}

  public class House
  {
    public string Address { get; init; }
    public string Owner { get; init; }
    public DateTime? Built { get; init; }
  }

  private static void DemoInit()
  {
      var house1 = new House
              {
                  Address = "Kings street 4",
                  Owner = "King",
                  Built = DateTime.Now
              };

    var house2 = new House();
    Console.WriteLine("house2 address: " + house2.Address??"empty address");
  }

  public static void Main(string[] args)
  {
    Console.WriteLine("Hello, World!");
    DemoRecord();
    DemoInit();
  }
}