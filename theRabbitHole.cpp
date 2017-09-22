///////////////////////////////////////////////////////
// TEMPLATES
///////////////////////////////////////////////////////

template<typename T> 
/* you can also use "class" instead of "typename", 
but don't confuse that with a class declaration... */
template<class T>

// you can use T as either a parameter type
template<typename T> 
void funcname(T param1)
{
	T a;
}

// or a return type
template<typename T> 
T funcname()
{
	T a;
	return a;
}

// or both!
template<typename T> 
T funcname(T param1)
{
	T a;
	return a;
}

// note if you assign the wrong datatype to T, you'll get an error
template<typename T> 
void funcname(T param1)
{
	T a;
	a = 42;
}
funcname("i am the very model of a modern major-general");


///////////////////////////////////////////////////////
// TEMPLATE FORWARDING
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// TEMPLATE (PARTIAL) SPECIALIZATION
///////////////////////////////////////////////////////
/* specialization is when you overload the generic rules for a template with 
 		a different set of rules for when it is passed a specific type*/
// say we have a vector class
class Vector
{
	T& at_index(size_t i);
	void push_back(const T& t);
};

template<template<typename> Container>
void print(const Container<int>& container)
{
	for(auto& thing : container) cout << thing << endl;
}
template<template<typename...> Tuple, typename...Args>
void print(const Tuple<Args...>& container)
{

}

// if you want to do something different with bools
template<>
class Vector<bool>
{
	// implementation goes here
}

// if you want to do something different when you get only 
// 		one int followed by only one float - order and quantity matter
template<>
void printf_t<int, float>(const int& a, const float& b)
{
	// implementation goes here
}


///////////////////////////////////////////////////////
// CURIOSLY RECURRING TEMPLATE PATTERNS (CRTPs)
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// ELLIPSES
///////////////////////////////////////////////////////

// ellipses will accept a list called Args of unknown length
template<typename... Args>
void printf_t(const char* format, const Args&... args)
{
	printf(format, args...);
}

printf_t("The data is: %s %d", x, y);

// this
template<size_t...I>
return func(std::get<I>(tuple)...);

// is the same as this (except that the ellipses above is more flexible and takes any quantity)
<0, 1, 2>
float operator[](int index)
return func(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));


///////////////////////////////////////////////////////
// OVERLOADING
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// SHARED POINTERS
///////////////////////////////////////////////////////
// shared pointers
// call new to allocate a new object
// if you call del on something 2x, it will crash (double delete)
// shared pointers use static variables
// if it exists in more than one instance it won't get deleted
// shared pointers override the del operator if there's more than 1 instance of it


///////////////////////////////////////////////////////
// RVALUE REFERENCES
///////////////////////////////////////////////////////
// lvalues are 'permanent' values that exist outside the scope of a class/function
// rvalue are temporary values that only exist inside the scope of a class/function

class Foo 
{
public:
	setName(const string&);
};

Foo::setName(const string& s)
{
	name = s;
}

/* gimmick = c++ allows you to assign an rvalue to a const reference
const int& is an lvalue that can reference an rvalue
but int& cannot reference an rvalue
because at some point in time, i could use int& to modify the temp value */

Foo f;
f.setName("Bob"); // "Bob" is created as a temporary rvalue - a cstring.
// The compiler is running something like: string temp1("Bob"), 
// so we have 1 copy of it so far in the Stack

// NOTE: cstrings can implicitly convert to strings, but strings cannot implicitly 
// convert to cstrings (technically, there's .c_str())

// It would get copied when we call setName() as a 2nd copy in the Stack. 
// NOTE: If setName() expects a string and you give it a string, or it
// expects a cstring and you pass it a cstring, then it won't make this 2nd copy.

// It would get copied AGAIN when we set name = s; 

// 3 potential copies of the same thing. If only there were a way to avoid this...
// Enter rvalue references: &&

// initializer list ":" will assign values AT creation rather than AFTER creation
string::string(const string& o) : size(o.size), arr(new char[o.size]) 
{
	// blah
}

// you can't del things that are on the stack, you can only delete things that are on the heap (created with "new")
// but std::move() can take whatever param its given and treat it as an rvalue
// so you can 'gut it' and take its pointer (indiana jones)
string s;
void eatStr(std::move(s));


string& string::operator=(const string& o)  // assign the "=" symbol to do something
{
	if (this == &o) return *this;  // why?
	delete arr;  // remove the array on the heap before you reassign the pointer that points to it because we'll lose track of it
	arr = new char[o.size];
	for (size_t i = 0; i < o.size; ++i) 
		arr[i] o[i];
		this->size = o.size;
		blah......
	return *this;
}

// but what if we do this instead
string& string::operator=(const string& o)
{
	// don't need to delete the array anymore, because we're gonna indiana jones it
	char* tmp = arr;
	arr = o.arr;
	o.arr = tmp;  // when the destructor is called, it will destroy o, so set it equal to tmp
	....... // set size and blah
	return *this;
}
// so change Foo::setName() to accept string&& instead of string&


string *p = &bob;
p->size = 3;
(*p).datamember;  // because . operator takes preference, so use parentheses to specify


int add(int a, int b) { return a + b; }
int multiply(const int& c, int d) { return c * d; }
// note that a, b, and d are temporary rvalues; their scope is limited to the function call.
// but by casting c as a const reference, we turn it into an lvalue that won't be deleted when the function ends
multiply(add(1,2), 4); 
// the result of add(1,2) would normally be temporary, but multiply() changes it

// use reference to make sure it isn't copied
// use const just in case they pass you a const even when you don't expect it

// the rvalue can be cast into a const lvalue reference but cannot be cast into 
//		an lvalue reference (difference being const)


// rvalue reference example: &&
// rvalue 

// you don't want to copy it, you have to create const reference
vector<string> a;
vector<T>::push_back(const T& t)
{
	if(size == capacity) doubleCap();
	arr[size] = t;
	++size;
}
vector<T>::push_back(T&& t)
{
	if(size == capacity) doubleCap();
	arr[size] = t;
	++size;
}
a.push_back("foo");



// why rvalue reference is beautiful
class string
{
private:
	char* ptr;
public:
	string(); //string x;
	string(const char*); // string x("foo"); string y = "foo";
	string(const string& x) //string x; string y(x); string z = x;
	{
		//allocate new array of same capacity as x //ptr = new char[x.capacity];
		//for loop copy from x to new array //for(int i = 0; i < x.capacity; ++i) ptr[i] = x.ptr[i];
	}
	operator=(const char*); //string x; x = "foo";
	operator=(const string& x) //string x; string y; x = y;
	{
		//check for self-assignment

		//delete old array // delete(ptr);
		//allocate new array of same capacity as x //ptr = new char[x.capacity];
		//for loop copy from x to new array //for(int i = 0; i < x.capacity; ++i) ptr[i] = x.ptr[i];
	}

	string(string&& x)
	{
		//steal array //ptr = x.ptr
		//fuck over x //x.ptr = nullptr
	}
	operator=(string&& x)
	{
		//check for self-assignment

		//indiana jones x //char* tmp = x.ptr; x.ptr = ptr; ptr = tmp;
	}

};


template<typename T>
void print(const T& t)
{
	cout << t << endl;
}

class Foo
{

};
ostream& operator<<(ostream& os, const Foo& f)
{
	return os << f.name << endl;
}



///////////////////////////////////////////////////////
// LAMBDAS
///////////////////////////////////////////////////////
// lambdas are used when you want to pass a function definition as a parameter!
// note that if it is used as a parameter, then the scope of that definition is 
// limited to that single instance of the function that calls it.


///////////////////////////////////////////////////////
// MULTIPLE INHERITANCE
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// VIRTUAL INHERITANCE
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// NESTED CLASSES
///////////////////////////////////////////////////////
// nested classes can reach the private data members of their containing class!
class LinkedList
{
private:
	int data;
public:  // can make public but it's better to use private and use the Iterator class
	class Node;  // nested class declaration
};

// nested class definition
class LinkedList::Node
{
private:
	LinkedList& containingList;  // reference to the LinkedList that this Node is contained in
								// we don't want a setter for this because references are const addresses
								// so the only time we want to be able to set it is when the Node is constructed
public:
	// declarations
	Node(const LinkedList& m);  // constructor, pass a const reference of its containing class rather than make a copy of it...
	int getData();
	LinkedList::Node& self();
};

// nested class function definitions
LinkedList::Node::Node(const LinkedList& m)
	: containingList(m)// constructor with initialization list, note that we set containingList to m
{
	//containingList = m;  // set what LinkedList this Node belongs to
	// NOTE: the above line won't work because we can't assign the containingList after its 
	// been made because it's a reference and references can't change what they refer to.
	// this is why we set this on the initialization list rather than inside the body
}

int LinkedList::Node::getData()
{
	return containingList.data; // it can access the private member of its containing class!!!!
}

LinkedList::Node& LinkedList::Node::self()
{
	return *this;  // return itself but as a reference! remember: "this" is a pointer
}

// example
LinkedList a;
LinkedList b;
LinkedList::Node n(a); // 'n' is an instance of the nested class Node inside LinkedList instance 'a'
num1 = n.getData();


/* by the way, regarding initialization lists:
if you ever have an inherited class but the parent class doesn't have a default constructor
inside that subclass's constructor, you must call the parent class's constructor in the initialization list.
you can't call the parent class's constructor anywhere else.
by the way, the compiler will ignore the order in which you initialize inside an initialization list...
THE ORDER MIGHT MATTER THOUGH!!! so the C++ standard tells compilers what order it must initialize in.
the order is: parent classes first from left to right, then members from top to bottom (any members not
in the initialization list will be defaulted, again in order from top to bottom), 
*/

///////////////////////////////////////////////////////
// OTHER FUN FACTS
///////////////////////////////////////////////////////
// Fun fact: you can use "unsigned char" if you wanna use chars as indices. Can't use
// signed char because you can't have negative indexes...
// If you leave it defaulted, each compiler will assign char as either signed or unsigned
// but there's no standard!!!
// Fun Fact: "new" will always create on the heap, everything else creates on the stack

// Pointer/Reference stuff
int* = pointer to an int
const int* = pointer to a int but treats it as const, so you can't change the int
int* const = const pointer to an int, so the address can't change
const int* const = const pointer to a int that is treated as const, so neither the address nor the int can change
// references are like pointers that don't use pointer syntax, they represent a single instance
// references and addresses are not the same thing
// references hold addresses but they are syntactically they are identical to instances
// instances can be rvalues or lvalues
int& = reference to an int, acts like int* const, so it can't change the address it refers to, but you can use the dot operator
int x;
int& m; // won't work because you have to point somewhere... because it's a const... it will always point to null, which will fail to compile
int& m = x;
int& m = 42; // won't work because in this case because 42 is an rvalue and will disappear, 
			// so when it disappears and that memory is overwritten by a new variable or whatever, 
			// then we would be referring to an address with unknown data in it, and we could 
			// modify that data, even if the data should be const - so this will fail to compile
const int& m = 42;  // this is okay though because now we're saying that whatever replaces the rvalue
					// we will not be able to modify using 'm'
// see the rvalue section for more details...