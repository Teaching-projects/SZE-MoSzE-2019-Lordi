#include "Tree.h"

void Tree::add(string name)
{
	if (!ifexist(head, name))
	{
		Node* n = new Node();
		head->child[head->childcount] = n;
		head->childcount++;
		n->parent = head;
		n->name = name;
	}
	else
	{
		cout << name << " are not allowed here!" << endl;
	}
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

void Tree::rm(Node* node, string foldername)
{
	Node* temp = node;
	Node* childs;
	if (temp->childcount > 0)
	{
		for (int i = 0; i < temp->childcount; i++)
		{
			if (temp->child[i]->name == foldername)
			{
				if (temp->child[i]->childcount == 0)
				{
					cout << "Directory has been deleted" << endl;
					delete temp->child[i];
					for (int j = i+1; j < temp->childcount; j++)
					{
						temp->child[j - 1] = temp->child[j];
					}
					temp->child[temp->childcount-1] = NULL;
					temp->childcount--;
				}
				else
				{
					cout << "Directory is not empty" << endl;
				}
			}
		}
	}
	else
	{
		cout << "This directory not exist!" << endl;
	}

}

void Tree::rmrf(Node* node, string foldername)
{
	Node* temp = node;
	Node* childs;
	if (temp->childcount > 0)
	{
		for (int i = 0; i < temp->childcount; i++)
		{
			if (temp->child[i]->name == foldername)
			{
				if (temp->child[i]->childcount == 0)
				{
					cout << "Directory has been deleted" << endl;
					delete temp->child[i];
					for (int j = i + 1; j < temp->childcount; j++)
					{
						temp->child[j - 1] = temp->child[j];
					}
					temp->child[temp->childcount - 1] = NULL;
					temp->childcount--;
				}
				else
				{
					deleteRecursive(temp->child[i]);
					for (int j = i + 1; j < temp->childcount; j++)
					{
						temp->child[j - 1] = temp->child[j];
					}
					temp->child[temp->childcount - 1] = NULL;
					temp->childcount--;

				}
			}
		}
	}
	else
	{
		cout << "This directory not exist!" << endl;
	}
}

void Tree::deleteRecursive(Node* entryPoint)
{
	if (entryPoint->childcount > 0)
	{
		for (int i = 0; i < entryPoint->childcount; i++)
		{
			deleteRecursive(entryPoint->child[i]);
		}
	}
	else
	{
		cout << "Directory has been deleted" << endl;
		delete entryPoint;
	}
}

void Tree::touch(Node* node, string filename)
{
	if (!ifexist(node, filename))
	{
		Node* n = new Node();
		head->child[head->childcount] = n;
		head->childcount++;
		n->parent = head;
		n->name = filename;
		n->runnable = true;
	}
	else
	{
		cout << filename << " are not allowed here!" << endl;
	}
}

bool Tree::ifexist(Node* nodem, string filename)
{
	bool RetVal = false;
	for (int i = 0; i < nodem->childcount; i++)
	{
		if (filename == nodem->child[i]->name)
		{
			RetVal = true;
		}
	}
	return RetVal;
}

