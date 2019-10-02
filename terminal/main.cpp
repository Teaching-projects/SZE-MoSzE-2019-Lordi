#include <iostream>
#include<string>
#include <cstdlib>

using namespace std;

class Node
{
public:
	Node* parent;
	Node* child[256];
	int childcount = 0;
	string name;

	Node()
	{
		parent = NULL;
		for (int i = 0; i < 256; i++) 
		{
			child[i] = NULL;
		}
		name = "root";
		
	}

};

class Tree
{
public: 
	Node* head;
	Node* root;
	string path = "root>";
	Tree()
	{
		head = new Node();
		root = head;
		head->name = "root";
	}

	void add(string name);
	void ls();
	void list(Node* node);
	void cd(Node* node, string name);
	void up(Node* node);
};

int main(void)
{
	Tree t;
	bool exit = false;
	string input;
	
	
	do {
		cout << t.path;
		getline(cin, input);

		string command = input.substr(0, input.find(' '));
		string second = input.substr(input.find(' ') + 1);
		if (command._Equal("mkdir"))
		{
			t.add(second);
		}
		else if(command._Equal("exit"))
		{
			exit = true;
		}
		else if(command._Equal("ls"))
		{
			t.list(t.head);
			
		}
		else if (command._Equal("cd") && !second._Equal(".."))
		{
			t.cd(t.head, second);
		}
		else if (command._Equal("cd") && second._Equal(".."))
		{
			t.up(t.head);
		}
	} while (!exit);
}

void Tree::add(string name)
{
	Node* n = new Node();
	head->child[head->childcount] = n;
	head->childcount++;
	n->parent = head;
	n->name = name;
	//system("cls");
}

void Tree::ls()
{
	Node* n = root;
	for (int i = 0; n->child[i] != NULL; i++)
	{
		cout << n->child[i]->name << endl;
	}
}

void Tree::list(Node* node)
{
	Node* n = node;
	
	for (int i = 0; n->child[i] != NULL; i++)
	{
		cout << n->child[i]->name << endl;
	}
}
void Tree::cd(Node* node ,string name)
{
	Node* n = node;
	
	for (int i = 0; n->child[i] != NULL; i++)
	{
		if (n->child[i]->name == name)
		{
			head = n->child[i];
			path += name + ">";
		}

	}
}

void Tree::up(Node* node)
{
	head = node->parent;
	path = path.substr(0, path.find_last_of('>'));
	path = path.substr(0, path.find_last_of('>')+1);
}
