import datetime
from collections import namedtuple
from collections import defaultdict

def letter_frequency(sentence):
    frequencies = defaultdict(int)
    for letter in sentence:
        frequencies[letter] += 1
    return frequencies


frqu = letter_frequency("this is a test, which is simple")
for it in frqu.keys():
    print("key '{}' => value {}".format(it, frqu[it]))

num_items = 0
def tuple_counter():
    global num_items
    num_items += 1
    return (num_items, [])  # return a tuple of (int, [])

d = defaultdict(tuple_counter) # dict of (int, [])
d['a'][1].append("hello")
d['b'][1].append("world")
print(d)

