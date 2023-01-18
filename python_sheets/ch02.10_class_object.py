class Fib(object):
    val = 10
    def fib(self, n):
        if n<=2:
            return 1
        return self.fib(n-1) + self.fib(n-2)

class Example(object):
    def __init__(self):
        self.name = "ex"

    def printex(self):
        print("This is an example")

class ClassA(object):
    def __new__(cls, arg):
        print("__new__ " + arg)
        #return super(ClassA, cls).__new__(cls)
        return object.__new__(cls)

    def __init__(self, arg):
        print("__init__ " + arg)

class ClassB(object):
    def __new__(cls, arg):
        print("__new__ " + arg)
        return object

    def __init__(self, arg):
        print("__init__ " + arg)

class CallableObject(object):
    def example(self, *args, **kwargs):
        print("I am callable!")

    def __call__(self, *args, **kwargs):
        self.example(*args, **kwargs)


def testfunction():
    f = Fib()
    print("fib(10)= {}".format(f.fib(10)))

    ex = Example()
    print(hasattr(ex, "name"))
    print(hasattr(ex, "printex"))
    print(hasattr(ex, "print"))
    print(getattr(ex, "name"))

    print("is Example subclass of object: {}".format(issubclass(Example, object)))
    print("ex class name is : {}".format(ex.__class__.__name__))

    a1 = ClassA("helloClassA")
    
    b1 = ClassB("helloClassB")
    pass


if __name__ == '__main__':
    testfunction()