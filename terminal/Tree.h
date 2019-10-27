#pragma once
#include <iostream>
#include<string>
#include <cstdlib>
#include "Node.h"
using namespace std;

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
	void rm(Node* node, string foldername);
	void rmrf(Node* node, string foldername);
	void deleteRecursive(Node* entryPoint);
	void touch(Node* node, string filename);
	bool ifexist(Node* nodem, string filename);
};