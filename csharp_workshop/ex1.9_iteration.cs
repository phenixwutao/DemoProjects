using System;
using System.Text;

class test
{
public static bool IsPrime(int number)
{
  if (number ==0 || number ==1) return false;
 
  bool isPrime = true;
  int counter = 2;

  while (counter <= Math.Sqrt(number))
  {
    if (number % counter == 0)
    {
      isPrime = false;
      break;
    }
    counter++;
  }

  return isPrime;
}


public static bool IsPrimeWithReturn(int number)
{
  if (number == 0 || number ==1) return false;
  int counter = 2;
 
  while (counter <= Math.Sqrt(number))
  {
    if (number % counter == 0)
    {
      return false;
    }
    counter ++;
  }
  return true;
}

public static int[] BubbleSort(int[] array)
{
  for(int i = 0; i < array.Length -1; ++i)
  {
    for(int j = 0; j < array.Length -i -1; ++j)
    {
      if(array[j] > array[j+1])
      {
        var t = array[j+1];
        array[j+1] = array[j];
        array[j] = t;
      }
    }
  }
  return array;
}

  public static void Main(string[] args)
  {
    {
    Console.WriteLine(IsPrime(28));
    Console.WriteLine(IsPrime(29));
    Console.WriteLine(Math.Sqrt(29));
    Console.WriteLine(IsPrimeWithReturn(28));
    Console.WriteLine(IsPrimeWithReturn(29));
    int[] randomNumbers = { 123, 22, 53, 91, 787, 0, -23, 5 };
    int[] sortedArray = BubbleSort(randomNumbers);
    for(int i = 0; i < sortedArray.Length; ++i)
      Console.Write(sortedArray[i] + " ");
    Console.WriteLine();
    }

    {
      var items = new int[] { 1, 2, 3, 4, 5 };
      foreach (int element in items)
      {
        Console.Write($"{element} ");
      }
      Console.WriteLine();
    }

    Console.WriteLine();
  }
}

