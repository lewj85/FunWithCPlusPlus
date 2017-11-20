#include <string>
using namespace std;

class PrefixTree
{
	struct Node;
public:
	PrefixTree() : root(new Node), terminal(new Node) {}
	bool insert(const string& str);
private:
	Node* root;
	Node* terminal;
};

struct PrefixTree::Node
{
	Node() : count(0) { for(unsigned char i = 0; i < 256; ++i) next[i] = nullptr; }
	unsigned int count;
	Node* next[256];
};

bool PrefixTree::insert(const string& str)
{
	unsigned int inc = (find(str) ? 0 : 1);
	Node* current = root;
	for(char c : str)
	{
		current->count += inc;
		if(current->next[c]) current = current->next[c];
		else
		{
			current->next[c] = new Node;
		}
	}
	bool result = !current->next[0];
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
	if(!find(str)) return;
	Node* current = root;
	for(char c : str)
	{
		--(current->count);
		Node* next = current->next[c];
		if(!current->count && current != root) delete current;
		current = next;
	}
	current->next[0] = nullptr;
	--(current->count);
	if(!current->count && current != root) delete current;
}