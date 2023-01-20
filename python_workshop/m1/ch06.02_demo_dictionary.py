import datetime
from collections import namedtuple

# dictionary page 162/183
# build a dict of [str, tuple [float,float,float,float]]
stocks = { "GOOG": (613.30, 625.86, 610.50), 
           "MSFT": (30.25, 30.70, 30.19) }

print(stocks["GOOG"])
print(stocks.get("GOOG"))
print("---- setdefault ----")
stocks.setdefault("GOOG", "INVALID") ## value exists, no change
# (613.3, 625.86, 610.5)
stocks.setdefault("BBRY", (10.50, 10.62, 10.39)) # set newly provided default value
print(stocks["GOOG"])
print(stocks["BBRY"])
for it in stocks.keys():
    prices = stocks[it]
    print("prices\t", prices[0:2])

## iterare using items()
for stock_name, stock_prices in stocks.items():
    print("stock name {}, prices {}".format(stock_name, stock_prices))

stocks["GOOG"] = (1.1, 2.2, 3.3)
stocks["GOOY"] = (1.3, 2.5, 3.7)
print(stocks["GOOG"])

for it in stocks.keys():
    prices2 = stocks.get(it)
    print("prices2:\t", prices2[0:3])
