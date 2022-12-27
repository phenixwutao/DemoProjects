using System;
using System.Text;


class test
{
public static int add(int a, int b)
{
  return a + b;
}

public class Book
{
  public string Title;
  public string Author;
  public string Publisher;
  public int Pages;
  public string Description;
}

public static void PrintBook(Book book)
{
  Console.WriteLine($"Author {book.Title}, " +
                    $"Title: {book.Title}, " +
                    $"Publisher: {book.Publisher}, " +
                    $"Description: {book.Description}.");
}

public class Rectangle
{
  private readonly decimal _width;
  private readonly decimal _height;
  public Rectangle(decimal width , decimal height )
  {
    _width = width; 
    _height = height;
  } 

  public decimal Area
  {
    get => _width * _height;
  }
}

  public static void Main(string[] args)
  {
    {
      Book book1 = new Book();
      book1.Author = "New Writer";
      book1.Title = "First Book";
      book1.Publisher = "Publisher 1";

      Book book2 = new Book();
      book2.Author = "New Writer";
      book2.Title = "Second Book";
      book2.Publisher = "Publisher 2";
      book2.Description = "Interesting read";
      PrintBook(book1);
      PrintBook(book2);
    }

    {
    }

    Console.WriteLine();
  }
}

