''' class multiple inheritances '''
class BaseClass:
    num_base_calls = 0
    def call_me(self):
        print("calling method on base class")
        self.num_base_calls += 1
    
class LeftSubClass(BaseClass):
    num_left_calls = 0
    def call_me(self):
        super().call_me()
        print("calling method on left Subclass")
        self.num_left_calls += 1


class RightSubClass(BaseClass):
    num_right_calls = 0
    def call_me(self):
        super().call_me()
        print("calling method on right Subclass")
        self.num_right_calls += 1

class SubClass(LeftSubClass, RightSubClass):
    num_sub_calls = 0
    def call_me(self):
        super().call_me()
        print("calling method on Subclass")
        self.num_sub_calls += 1


class CallableObject(object):
    def example(self, *args, **kwargs):
        print("I am callable!")
    def __call__(self, *args, **kwargs):
        self.example(*args, **kwargs)

'''######################################################################'''
def testmain():
    a = SubClass()
    a.call_me()
    print(a.num_sub_calls, a.num_left_calls, a.num_right_calls, a.num_base_calls)
    ex = CallableObject()
    ex()


if __name__ == "__main__":
    testmain()

