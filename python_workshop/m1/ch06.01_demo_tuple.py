import datetime
from collections import namedtuple

def middle(stock, date):
    # unpack the tuple from tuple function pass-in parameter
    symbol, current, high, low = stock
    return (((high + low) / 2), date) ## function return (amount, date) as a tuple


##############################################################################
#                 pass tuple into function call,      date argument
mid_value, date = middle(("FB", 75.00, 75.03, 74.90), datetime.date(2014, 10, 31))
# unpack tuple returned from middle function (mid_value, date)

print(mid_value)
print(date)

# slice from tuple
stock2 = middle(("FB", 75.00, 75.56, 74.90), datetime.date(2014, 10, 18))
date2 = stock2[1]
print("date2 is: ", date2)

# named tuple with tuple column headers
Stock = namedtuple("Stock", "symbol current high low")
stock = Stock("FB", 75.00, high=75.03, low=74.90)
