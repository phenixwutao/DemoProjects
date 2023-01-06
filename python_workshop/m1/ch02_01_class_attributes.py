import math
from math import sqrt, cos
from math import sin as SinFunc

from module1 import database
from module1 import fibo

# from module import *

class Point:
  """
  this is Point class demo
  """
  def __init__(self):
    self._name = "No name"         # protected internal member: class/subclass can access
    self.__note = "financial note" # private member: class method can access
    self.x = 0
    self.y = 0
    pass

  def reset(self):
    self.x = 0
    self.y = 0

  def move(self, a, b):
    self.x += a
    self.y += b

  def calculate_distance(self, rhs):
    return math.sqrt(
      (self.x - rhs.x) ** 2.0 +
      (self.y - rhs.y) ** 2.0
    )

def main():
  ''' this main function is for self testing purpose '''
  p1 = Point()
  p2 = Point()
  p1.x = 2
  p1.y = 3
  p2.x = 3
  p2.y = 6
  print(p1.x, p1.y)
  print(p2.x, p2.y)

  dis1 = p1.calculate_distance(p2);
  print("distance is", dis1)
  p1.reset()
  p2.reset()
  print(p1.x, p1.y)
  print(p2.x, p2.y)

  p3 = Point()
  Point.reset(p3)
  print(p3.x, p3.y)
  p3.move(2,3)
  print(p3.x, p3.y)
  print(p3.__doc__)
  print(p3._name)
  #print(p3.__note) # error

  print("---------------")
  database.initialize_database()
  db = database.Database()
  print(database.database, db)
  print(fibo.fib(6))


if __name__ == '__main__':
  main()

