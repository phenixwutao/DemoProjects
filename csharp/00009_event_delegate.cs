using System;
using System.Text;


public class PriceChangedEventArgs : EventArgs
{
  public readonly decimal LastPrice;
  public readonly decimal NewPrice;

  public PriceChangedEventArgs (decimal lastPrice, decimal newPrice)
  {
    LastPrice = lastPrice; NewPrice = newPrice;
  }
}

public class Stock
{
  string symbol;
  decimal price;

  public Stock (string symbol) {this.symbol = symbol;}

  public event EventHandler<PriceChangedEventArgs> PriceChanged;

  protected virtual void OnPriceChanged (PriceChangedEventArgs e)
  {
    Console.WriteLine("call OnPriceChanged {0}", e.LastPrice);
    PriceChanged?.Invoke(this, e);
  }

  public decimal Price
  {
    get { return price; }
    set
    {
    if (price == value) return;

    decimal oldPrice = price;
    price = value;

    OnPriceChanged (new PriceChangedEventArgs (oldPrice, price));
    }
  }
}

class test
{

  static void Main()
  {
    Stock stock = new Stock ("THPW");
    stock.Price = 27.10M;
    // Register with the PriceChanged event
    stock.PriceChanged += stock_PriceChanged;
    stock.Price = 31.59M;
    Console.WriteLine();
  }

  static void stock_PriceChanged (object sender, PriceChangedEventArgs e)
  {
  if ((e.NewPrice - e.LastPrice) / e.LastPrice > 0.1M)
    Console.WriteLine ("Alert, 10% stock price increase!");
  }

}
