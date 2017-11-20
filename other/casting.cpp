char myString[10];
char* myCopy = str;
// right now myCopy and myString are the same thing: a pointer to a char array
char** ptr = myString; 
// ptr holds the memory location of myString 
// when is this practical? when you want to point to a changing pointer (ie. when a pointer will point at different strings/locations in memory)

// CASTING
char** myStringLoc = &myString;
char** myStringLoc = (char**)ptr
(char**)myStringLoc;  // syntax for C and C# - casts myString as a pointer to a pointer - (char**)(myString)
*myStringLoc; // will dereference and point to the the location of ptr, which has the starting position of myString
*myStringLoc[2];  // will give us the 3rd letter - IF IT EXISTS - of the char array at ptr

int(myString);  // syntax for C++ and python - calls int's constructor
// preferred C++ syntax - almost exclusively used for pointers and references
static_cast<T>(myString);  // happens during compile-time, so no virtual inheritance
dynamic_cast<T>(myString);  // run-time, so virtual inheritance is okay - vtables are referenced at run-time
reinterpret_cast<T>(myString);  // typically not safe to use because it's C-style casting

// if you want to stick a Cat into a vector of Mammal pointers then you can cast the Cat pointer as a Mammal pointer and then stick it in
// use InheritedClass : BaseClass to let compiler know that the class is inheriting from it
// upcasting - cast from Cat pointer to Mammal pointer - goes up the hierarchy - allowed for static_cast
// downcasting - cast from Mammal pointer to Cat pointer - goes down the hierarchy - not allowed for static_cast - Mammal doesn't even know Cat exists (base classes don't/shouldn't know all children) - use dynamic_cast instead because it will use vtables to find the children methods

// Abstraction - Mammal has speak() declared but not defined, but we want to use Cat's
// if we want to make m->speak(); use Cat's speak() instead of Mammal's speak();
// virtual void speak() = 0;  // goes inside Mammal to make speak() a virtual method, = 0 makes it 'pure virtual' 
// the point of making methods virtual is to make them overwriteable
// 
Mammal M;
Mammal* m = &M;
M.speak();  // uses Mammal's speak
m->speak();  // uses Mammal's speak

Cat C;
Cat* c = &C;
C.speak();  // uses Cat's speak
c->speak();  // uses Cat's speak

Mammal* m = &C;  // now Mammal pointer m points to a Cat object so we can stick a Cat into an array of Mammals
m->speak();  // if speak() is virtual inside Mammal, then uses Cat's speak
m->speak();  // if speak() is not virtual inside Mammal, then uses Mammal's speak still!!!

// Non-Abstract Virtual - when Mammal has breathe() but Cat overrides breathe() with a chance to cough up a hairball

// ask about 'static' - "exists without instance" - global variable/function but does not have global scope

// "Stack is a stack of mini-heaps. Don't quote me on that." - Kenan Millet

int myArr[20] = {0}; // will zero-initialize this in C++, not in C
char myString[20](); // adding () will zero-initialize this in C++, not in C
myString[5];  // same as below
*(myString+5);  // same as above