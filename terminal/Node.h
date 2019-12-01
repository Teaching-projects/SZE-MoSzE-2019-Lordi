#pragma once
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
	bool runnable = false;
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
	Node(Node* parent, string name)
	{
		this->parent = parent;
		this->name = name;
	}

};
