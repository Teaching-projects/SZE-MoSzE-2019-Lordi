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
		string command = "";
		string second = "";
		string third = "";
		int j = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
			{
				j++;
				continue;
			}
			if (j == 0)
			{
				command += input[i];
			}
			else if (j == 1)
			{
				second += input[i];
			}
			else if (j == 2)
			{
				third += input[i];
			}


		}


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
		else if (0 == command.compare("rm") && 0 != second.compare("-rf") && third.length() == 0)
		{
			t.rm(t.head, second);
		}
		else if (0 == command.compare("rm") && 0 == second.compare("-rf"))
		{
			t.rmrf(t.head, third);
		}
		else if (0 == command.compare("touch"))
		{
			t.touch(t.head, second);
		}
		else
		{
			cout << "Command not exist!" << endl;
		}
	} while (!exit);
}


