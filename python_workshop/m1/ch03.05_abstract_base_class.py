import math
# abstract base class ==> abc
import abc 

class OddContainer:
    def __contains__(self, x):
        if not isinstance(x, int) or not x % 2:
            return False
        return True


class MediaLoader(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def play(self):
        pass

    @abc.abstractproperty
    def ext(self):
        pass

    @classmethod
    def __subclasshook__(cls, C):
        if cls is MediaLoader:
            attrs = set(dir(C))
            if set() <= attrs:
                return True
        return NotImplemented

class Ogg(MediaLoader):
    ext = '.Ogg'
    def play(self):
        print("it will play an ogg file")
        pass


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, p):
        return math.sqrt((self.x-p.x)**2 + (self.y-p.y)**2)


class Polygon:
    def __init__(self):
        self.vertices = []

    def add_point(self, point):
        self.vertices.append(point)

    def perimeter(self):
        perimeter = 0
        points = self.vertices + [self.vertices[0]]
        for i in range (len(self.vertices)):
            perimeter += points[i].distance(points[i+1])
        return perimeter


class Color:
    def __init__(self, rgb_value, name):
        self.rgb_value = rgb_value
        self._name = name

    def _set_name(self, name):
        if not name:
            raise Exception("Invalid Name")
        self._name = name
        
    def _get_name(self):
        return self._name

    name = property(_get_name, _set_name)


class Silly:
    def _get_silly(self):
        print("You are getting silly")
        return self._silly

    def _set_silly(self, value):
        print("You are making silly {}".format(value))
        self._silly = value

    def _del_silly(self):
        print("Whoah, you killed silly!")
        del self._silly

    ## property with set/get/del
    silly = property(_get_silly, _set_silly, _del_silly, "This is a silly property")


class Foo:
    @property
    def foo(self):
        return self._foo

    @foo.setter
    def foo(self, value):
        self._foo = value

    @foo.deleter
    def foo(self):
        del self._foo



class NewSilly:
    ''' NewSilly class using property decorators'''
    @property
    def silly(self):
        '''This is a NewSilly property'''
        print("You are getting NewSilly")
        return self._silly

    @silly.setter
    def silly(self, value):
        '''This is a NewSilly setter'''
        print("You are making NewSilly {}".format(value))
        self._silly = value

    @silly.deleter
    def silly(self):
        '''this is a NewSilly deleter'''
        print("Whoah, you killed NewSilly!")
        del self._silly


def testfunction():
    odd_container = OddContainer()
    ogg = Ogg()
    ogg.play()
    print("test perimeter from polygon")
    ps = Polygon()
    ps.add_point(Point(1,1))
    ps.add_point(Point(1,2))
    ps.add_point(Point(2,1))
    ps.add_point(Point(2,2))
    print("the perimeter is: {} ".format(ps.perimeter()))
    color1 = Color("#0000ff", "bright red")
    print("color's name is: ", color1.name)
    print("----- test silly class:")
    silly1 = Silly()
    silly1.silly = "funny"
    print(silly1.silly)
    del silly1.silly

    silly2 = NewSilly()
    silly2.silly = "aha"
    print(silly2.silly)
    del silly2.silly
    pass

''' ########## self testing part ######### '''
if __name__ == '__main__':
    testfunction()