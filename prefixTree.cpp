#include <string>
using namespace std;

class PrefixTree
{
	// class data members are private by default and struct data members are public by default
	struct Node;  // this is not a data member though, it's a "Forward Declaration" - but since it's not defined, we can only use pointers/references to it
	// pointers always take 32 bits on a 32-bit system, or 64 bits on a 64-bit system, 
	// and since the pointer size never changes, we can forward declare it without a definition
public:
	PrefixTree() : root(new Node), terminal(new Node) {}  // why after : instead of inside {}? 
	// it's called an "Initialization List". it assigns values to data members before running the constructor's {} stuff
	// note that you can't run code in an Initialization List, you can only assign data member values
	// useful for inheritance and also if you don't want to assign default values and then re-assign them with param values
	// syntax is datamembername(data) - "new" is only needed if you're making a new object on the heap and you want it outside the function scope
	// otherwise you could just do PrefixTree() : root(Node()), etc
	bool insert(const string& str);
private:
	Node* root;
	Node* terminal;  // rather than use boolean data member inside Nodes to show a terminating node, 
					// we will have the myNode->next[0] point to this so we know it's terminating
};

struct PrefixTree::Node  // we need :: because Node exists only within the scope of PrefixTree - called "Scope Resolution Operator"
						// useful because "Node" is a common word and we want to be specific that this definition is the PrefixTree version
						// also useful if we want to hide the fact that PrefixTree has Node objects
{
	Node() { for(unsigned char i = 0; i < 256; ++i) next[i] = nullptr; }  // use nullptr because next[] is an array of pointers and we are initializing it
	Node* next[256];  // this wastes a lot of space, but we can use chars as indices. ie. myNode->next['a']
					// could go with 95 for typable characters or 26 for lowercase/uppercase letters (not both) but then you need a mapping function
};

bool PrefixTree::insert(const string& str)
{
	Node* current = root;
	for(char c : str) // C++ "for each" loop - like python's "for x in y" 
	{
		if(current->next[c]) current = current->next[c];
		else
		{
			current->next[c] = new Node;
		}
	}
	bool result = !current->next[0];  // same as !(current->next[0]) because ! has a lower priority
	current->next[0] = terminal;
	return result;
}

bool PrefixTree::find(const string& str)
{
	Node* current = root;
	for(char c : str)
	{
		if(current->next[c]) current = current->next[c];
		else return false;
	}
	return current->next[0];
}

void PrefixTree::remove(const string& str)
{
	Node* current = root;
	for(char c : str)
	{
		if(current->next[c]) current = current->next[c];
		else return;
	}
	current->next[0] = nullptr;
}

// C# properties
// like private data members where you have to write getters and setters for them