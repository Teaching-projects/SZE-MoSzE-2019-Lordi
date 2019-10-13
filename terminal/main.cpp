#include <iostream>
#include<string>
#include <cstdlib>
#include "Tree.h"
using namespace std;

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
		if (0 == command.compare("mkdir"))
		{
			t.add(second);
		}
		else if(0 == command.compare("exit"))
		{
			exit = true;
		}
		else if(0 == command.compare("ls"))
		{
			t.list(t.head);
			
		}
		else if (0 == command.compare("cd") && 0 != second.compare(".."))
		{
			t.cd(t.head, second);
		}
		else if (0 == command.compare("cd") && 0 == second.compare(".."))
		{
			t.up(t.head);
		}
		else
		{
			cout << "Command not exist!" << endl;
		}
	} while (!exit);
}


