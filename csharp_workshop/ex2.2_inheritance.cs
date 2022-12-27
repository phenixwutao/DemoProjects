using System;
using System.Text;


class test
{
  public class Tile {}

  public class Motor
  {
    public void Move(){}
  }

  public class Trap
  {
    public void Damage(){}
  }

  public class MovingTile :  Tile
  {
    private readonly Motor _motor;
    public MovingTile(Motor motor)
    {
      _motor = motor;
    }
    public void Move() { _motor.Move(); } // method delegate
  }

  public class TradpTile :  Tile
  {
    private readonly Trap _trap;
    public TradpTile(Trap trap)
    {
      _trap = trap;
    }
    public void Damage() { _trap.Damage(); }
  }

  // model a moving and trap tile
  public class MovingTrapTile : Tile
  {
    private readonly Motor _motor;
    private readonly Trap _trap;
    public MovingTrapTile(Motor motor, Trap trap)
    {
      _motor = motor;
      _trap = trap;
    }
    public void Move() { _motor.Move(); }
    public void Damage() { _trap.Damage(); }

  }

  public static void Main(string[] args)
  {
    {
    }

    {
    }

    Console.WriteLine();
  }
}

