import math

class Pet:
  """
  this is a Pet class for demo purpose
  """
  is_human = False
  owner = "Mike Smith"

  def __init__(self, height):
    self.height = height
    pass

# testing this class
if __name__ == '__main__':
  chubbles = Pet(height = 5)
  print(chubbles.__doc__)
  print(chubbles.__dir__)
