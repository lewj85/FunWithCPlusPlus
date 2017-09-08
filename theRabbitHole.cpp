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



// some basic principles about C++
int add(int a, int b) { return a + b; }
int multiply(const int& c, int d) { return c * d; }
// note that a, b, and d are temporary; their scope is limited to the function call.
// but by casting c as a const reference, we trick the compiler into thinking that
// c is permanent, allowing us to do some nifty things
multiply(add(1,2), 4); 
// the result of add(1,2) would normally be temporary, but multiply() changes it



// rvalue reference example: &&
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


// ellipses will accept a list called Args of unknown length
template<typename... Args>
void printf_t(const char* format, const Args&... args)
{
	printf(format, args...);
}

printf_t("The data is: %s %d", x, y);

template<size_t...I>
return func(std::get<I>(tuple)...);


<0, 1, 2>
float operator[](int index)
return func(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));



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

//template specialization
template<>
class Vector<bool>
{

}

template<>
void printf_t<int, float>(const int& a, const float& b)
{
	//implementation...
}
