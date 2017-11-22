void myFunc1(int arr1D[]){}  // pass an int pointer by value, which basically passes the array by reference
void myFunc1(int* arr1D){}  // identical to the above

void myFunc2(int arr2D[][]){}  // compiler error for multidimensional arrays, need to put bounds for every dimension after the first  
void myFunc2(int arr2D[][2]){}  // fine, but annoying. we don't want to have to specify size every time
void myFunc2(int* arr2D){}  // this doesn't work because it's the same as myFunc1() above
void myFunc2(int* arr2D[]){}  // this doesn't work because it expects an int** 
// why does it expect an int**? because when you pass it an array of unknown size (arr2[]) it attempts to replace that with a pointer
// so how do we pass a 2D array of unknown size?

arr1D[0]; // arr1D is a pointer (holds a memory location), arr1D[0] is equivalent to *(arr1D + 0)
arr1D[1]; // equivalent to *(arr1D + 1) where 1 is the size of the object - here we have ints so + 1 is one byte away
// NOTE: void pointers are the exception because they must be cast to pointers before they can be incremented/added to
*arr1D; // would give the first value in the array

int x[][3] = {{0,1,2}, {3,4,5}};
int* y[];  // would fail to compile - need to specify size of array
int* y[2];  // this is fine
int* y[] = {x[0], x[1]};  // y is identical to x, even though x was created without int* and y was created with int*
int* y[]{x[0], x[1]};  // identical to above, uses an initializer, which is similar to a constructor but for arrays - look up "aggregate initializers"
// NOTE: even though x and y are identical in memory, if you try to pass x as a parameter you will get an error, while passing y is no problem!
// also, we can't set x[0] to nullptr, but we can set y[0] to nullptr
// x is a 2D array of ints. even though under the hood it's actually a 1D array of int pointers, we don't want to ever expect nullptr to replace an int array
// y is a 1D array of int pointers, so we can expect the possibility of nullptr
int** z = new int*[2];  // this creates a pointer to an array of 2 int pointers on the heap
// NOTE: the above doesn't say how many ints will be in each array in z, so do that next
// NOTE: we could make every int array of the second dimension a different length!
*z[0] = {1,2,3}; // fails to compile because you need to create them permanently (rather than use them as rvalues) to have a permanent memory location for them 


// non-type template paramater
template<typename T>
myFunc1(T){}
template<typename T>
T myFunc2(){}

int x;
myFunc1(x);  // this would work
x = myFunc2();  // but this would fail to compile
// the way to fix it is to assign <int> with an "explicit call"
myFunc1<int>(x);
x = myFunc2<int>();

// only need ; after {} for classes, structs, and unions (and aggregate initializers)
// unions are space-sharing structs - all variables inside a union share the same space in memory
union Banana
{
	int i;
	bool j;
}
Banana b;
b.i = 10;
cout << b.j;  // true

// commonly used with matrices
union Matrix
{
	// _m and data use the same space in memory
	float _m[16];  // index the array of floats as a 1D array
	float data[4][4];  // index the array of floats as a 2D array
	// note that if you have variables of different sizes, it will take the biggest one and add padding to 
	// all smaller ones to align their least-significant bit to the big one
}

// use references instead of pointers when you can, because pointers can be nullptr
void myFunc3(int v){}  // myFunc3(x) - pass x by value.
void myFunc3(int& v){}  // myFunc3(x) - pass x by reference. any changes to x inside the function will be saved outside the function scope - under the hood it's the same as a pointer, but inside the function you don't have to dereference x before using it. inside: x = 5;
void myFunc3(int* v){}  // myFunc3(xptr) - pass x by pointer. int* xptr = &x. inside: *xptr = 5;
void myFunc3(const int& v){}  // x will always be 5, can't be changed
void myFunc3(const int* v){} // value of x can't change, same as above except you need to dereference xptr. inside *xptr;
void myFunc3(int& const v){} // pointless because references are already guaranteed to be const memory locations by definition
void myFunc3(int* const v){} // can't modify the pointer's value (where the pointer points)
void myFunc3(const int* const v){} // can't modify the pointer's value or x's value
void myFunc3(int*& v){}  // pointer to pointer under the hood, but you can modify the pointer without dereferencing it. inside: xptr = &y;
void myFunc3(int** v){}  // same as above but you have to dereference xptr. inside: *xptr = &y;
void myFunc3(int**& v){}  // handles