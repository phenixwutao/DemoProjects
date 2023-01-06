class Database:
  def __init__(self):
    print("init database")
  pass

database = None

def initialize_database():
  global database # module level value
  database = Database()

