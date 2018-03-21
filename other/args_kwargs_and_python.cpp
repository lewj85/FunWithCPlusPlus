/* In C++, just use a Struct wrapper and define optional parameters as 
fields of a struct. */
struct args_struct {
    const char* title = "";
    int year = 2018;
    float percent = 0.0;
};

void test_function(int a, int b, const args_struct& args = args_struct())
{
    printf("title: %s\nyear: %d\npercent: %.2f\n",
        args.title, args.year, args.percent);
}

int main()
{
    args_struct args;
    args.title = "the title";
    args.percent = 61.80;
    test_function(1, 2, args);

    /* Note: in pure C brace initalizers could be used instead
       but then you lose custom defaults -- non-initialized
       fields are always zero.
       args_struct args = { .title = "the title", .percent = 61.80 };
    */
	
    return 0;
}


/*
PYTHON


def test_var_args(farg, *args):
    print "formal arg:", farg
    for arg in args:
        print "another arg:", arg

test_var_args(1, "two", 3)

Results:
formal arg: 1
another arg: two
another arg: 3



def test_var_kwargs(farg, **kwargs):
    print "formal arg:", farg
    for key in kwargs:
        print "another keyword arg: %s: %s" % (key, kwargs[key])

test_var_kwargs(farg=1, myarg2="two", myarg3=3)

Results:
formal arg: 1
another keyword arg: myarg2: two
another keyword arg: myarg3: 3



def test_var_args_call(arg1, arg2, arg3):
    print "arg1:", arg1
    print "arg2:", arg2
    print "arg3:", arg3

args = ("two", 3)
test_var_args_call(1, *args)

Results:
arg1: 1
arg2: two
arg3: 3



def test_var_args_call(arg1, arg2, arg3):
    print "arg1:", arg1
    print "arg2:", arg2
    print "arg3:", arg3

kwargs = {"arg3": 3, "arg2": "two"}
test_var_args_call(1, **kwargs)

Results:
arg1: 1
arg2: two
arg3: 3
*/

/* More Python stuff
Function Documentation:
def add(a,b):
    """ Simple function - add 2 numbers"""
    return a+b
 
>>> help(add)
Help on function add in module __main__:

add(a, b)
    Simple function - add 2 numbers

 

Function Annotations (Python 3):
def add(a:"first number" = 0,
        b:"second number" = 0) -> "sum of a and b":
    return a+b

for item in add.__annotations__.items():
    print(item)

# ('a', 'first number')
# ('b', 'second number')
# ('return', 'sum of a and b')

*/

/* Lambda functions in Python:

ls = [2,4,6]
newlist = map(lambda item:item * 2, ls)
for n in newlist:
    print(n) 
# 4
# 8
# 12


NOTE: lambda functions cannot contain branches or loops but can 
contain conditional expression. Usually a simple expression:


import random

f1 = lambda x:x+10
f2 = lambda :random.randint(100,200)
f3 = lambda x,y:x+y
compare=lambda a,b: -1 if a < b else (+1 if a > b else 0)

print( f1(10) ) # 20
print( f2() ) # prints random number 
print( f3(2,3)) # 5
print( compare(10,20) ) # -1
*/

