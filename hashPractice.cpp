// hashing functions return an integer that is converted into an index using modX where X is the length of the array 
#include <unordered_map>  // hash map - takes key and spits out a value 
#include <unordered_set>  // hash set - keys = values, normal set that's implemented using a hash table instead of a binary search tree 
#include <string>

// set: only contain unique values (ie. binary search tree) and orders them
// map: only contain unique key-value pairs (ie. binary search tree that has key-value pairs, orders by key, and returns values)
// so a map is a type of set

// multiset: a set that supports duplicates
// multimap: a map that supports duplicates, it supports multiple values per key - like hash chaining collisions but built-in

// maps are what we normally think of for hash tables (ie. python's dictionaries)

//std::unordered_map<keytype, valuetype>
//std::unordered_map<string, int> // for example

std::unordered_map<std::string, int> myMapName;  // declaring doesn't exist in C++, this is calling the constructor of unordered_map of type <string, int>
std::pair<std::string, int> myPair;
std::make_pair(std::string("jesse"), 42);  // if you don't use string() it will see it as a cstring
std::make_pair<std::string, int>("jesse", 42);  // this would work too, but you need to specify "string" somewhere or it will make a cstring, int pair
myMapName["Hello"] = 42;  // this works without string() because myMapName's declaration above specifies that the keys will be strings, so it will convert it for you
myMapName.insert(myPair);  // insert() expects a pair
myMapName.insert(std::make_pair(std::string("jesse"), 42);  // can create that pair inside insert()
myMapName.insert(std::make_pair<std::string, int>("jesse", 42));  // this works too
myMapName.emplace("jesse",42);  // emplace() doesn't need string() because we already specified it when we declared myMapName


// template specialization for templated hash class so unordered_map uses our hash instead of the built-in
// string is already specialized so we need to create a struct called Password and stick the string inside it so we can specialize the struct Password instead
struct Password
{
	string pw;
};

// salting = XOR passwords with a long number before you hash them - screws up rainbow tables
// a kernel is a hardware-usage library for use in software - linux is a kernel (ubuntu is the os), unix is the kernel for mac, windowsNT for windows
// os is one level above kernel - uses the kernel, adds timers, threads, etc

