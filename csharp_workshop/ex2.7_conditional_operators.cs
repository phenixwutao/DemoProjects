using System;
using System.Text;
using static System.Math;

class Test
{

  public class Account
  {
    private decimal? _balance; // nullable primitive type
    public Account()
    {
      _balance = 0;
    }
    public Account(decimal amt)
    {
      _balance = amt;
    }

    // Always overload operators in pairs
    public static bool operator<(Account acc1, Account acc2)
    {
      return acc1?._balance < acc2?._balance;
    }

    public static bool operator>(Account acc1, Account acc2)
    {
      return acc1?._balance > acc2?._balance;
    }

    public static bool operator==(Account acc1, Account acc2)
    {
      return acc1?._balance == acc2?._balance;
    }

    public static bool operator!=(Account acc1, Account acc2)
    {
      return acc1?._balance != acc2?._balance;
    }
  }

  public static void Main(string[] args)
  {
    string name = null;
    Console.WriteLine("name is " + (string.IsNullOrEmpty(name) ? "empry" : name));
    bool? isStartedWithA = name?.StartsWith('A');
    Console.WriteLine("isStartedWithA " + isStartedWithA);

    string owner1 = "Rob";
    string owner2 = "Ryan";
    string newowner = owner1 ?? owner2;
    Console.WriteLine("newowner " + newowner);
    owner1 = null;
    newowner = owner1 ?? owner2;
    Console.WriteLine("newowner " + newowner);

    // value-left ?? value-right
    // if value-left is not null, return value-left, otherwise return value-right
    {
      var account1 = new Account(-1.01m);
      var account2 = new Account(1.01m);
      var account3 = new Account(1001.99m);
      var account4 = new Account(1001.99m);
      Console.WriteLine(account1 == account2);
      Console.WriteLine(account1 != account2);
      Console.WriteLine(account2 > account1);
      Console.WriteLine(account1 < account2);
      Console.WriteLine(account3 == account4);
      Console.WriteLine(account3 != account4);
    }
  }
}

