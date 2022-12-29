using System;
using System.IO; // File class
using System.Text;
using static System.Math;
using System.Collections.Generic;

/*
lambda expression definition:

(sender, e) =>
{
// expression or block
};

*/
public static class SentenceUtil
{
    public static string ReverseWords(string sentence)
    {
        Func<string,string> swapWords =
        (phrase) => {
            const char Delimit = ' ';
            string[] words = phrase.Split(Delimit).Reverse();
            return string.Join(Delimit, words);
        };
        return swapWords(sentence);
    }
}

public class Test
{

  public static void Main(string[] args)
  {
    {
        var names = new List<string>
            {
            "The A-Team",
            "Blade Runner",
            "There's Something About Mary",
            "Batman Begins",
            "The Crow"
            };

        names.Sort();
        Console.WriteLine("Sorted names:");
        foreach (var name in names)
        {
            Console.WriteLine(name);
        }
        Console.WriteLine("----------------------------");

        const string Noise = "The ";
        names.Sort( (x, y) =>
          {
            if (x.StartsWith(Noise))
            {
                x = x.Substring(Noise.Length);
            }
            if (y.StartsWith(Noise))
            {
                y = y.Substring(Noise.Length);
            }
            return string.Compare(x , y);
          });

        Console.WriteLine($"Sorted excluding leading '{Noise}':");
        foreach (var name in names)
        {
            Console.WriteLine(name);
        }
    }
    Console.WriteLine();

    {
        string sentence = "This is a test sentence.";
        var new_sentence = SentenceUtil.ReverseWords(sentence);
        Console.WriteLine(new_sentence);
    }
    Console.WriteLine();
  }
}