#include "Tree.h"

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
void Tree::cd(Node* node, string name)
{
	Node* n = node;
	bool success = false;
	for (int i = 0; n->child[i] != NULL; i++)
	{
		if (n->child[i]->name == name)
		{
			head = n->child[i];
			path += name + ">";
			success = true;
		}

	}
	if (success == false)
	{
		cout << name << " DIR not exist!" << endl;
	}

}

void Tree::up(Node* node)
{
	if (root != head)
	{
		head = node->parent;
		path = path.substr(0, path.find_last_of('>'));
		path = path.substr(0, path.find_last_of('>') + 1);
	}
	else
	{
		cout << "You are in the root directory" << endl;
	}
}