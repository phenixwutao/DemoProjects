class EvenOnly(list):
    def append(self, integer):
        if not isinstance(integer, int):
            raise TypeError("only integers can be added")
        if integer%2:
            raise ValueError("only even numbers can be added")
        super().append(integer)


def funny_division2(number):
   try:
      if number == 13:
         raise ValueError("13 is unlikcy number")
      return 100 / number
   except (ZeroDivisionError, TypeError, ValueError):
      return "enter a number other than zero or 13"


def funny_division3(number):
   try:
      if number == 13:
         raise ValueError("13 is unlikcy number")
      return 100 / number
   except ValueError as e:
      return "No no, not 13 : " + str(e.args)
   except (ZeroDivisionError):
      return "Enter a number other than zero"
   except TypeError as e:
      return "Enter a numberical value, details: " + str(e.args)
   

if __name__ == "__main__":
    try:
      e = EvenOnly()
      e.append("a string")
      e.append(3)
      e.append(4)
    except Exception as err:
      print("catch exception")
      print(f"Unexpected {err=}, {type(err)=}")


    for val in (0, "hello", 50.0, 13):
      print("testing {}:".format(val), end=" ")
      print(funny_division3(val))
