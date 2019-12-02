#include <iostream>
#include<string>
#include <cstdlib>
#include "Tree.h"
#include <vector>
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
		vector<string> path;
		string curr = "";
		string third = "";
		bool longpathcmd = false;
		
		int j = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
			{
				j++;
				continue;
			}
			if (input[i] == '/')
			{
				path.push_back(curr);
				curr = "";
				continue;
			}

			if (j == 0)
			{
				command += input[i];
			}
			else if (j == 1)
			{
				curr += input[i];
			}
			else if (j == 2)
			{
				third += input[i];
			}
		}
		path.push_back(curr);

		if (path.size() > 1)
		{
			longpathcmd = true;
		}

		for (const string& second : path)
		{
			if (command == "mkdir")
			{
				if (second == "..")
				{
					t.up(t.head);
				}
				else
				{
					if (!t.add(second)) 
					{
						break;
					}
					if (longpathcmd)
					{
						t.cd(t.head, second);
					}
				}
			}
			else if (command == "exit")
			{
				exit = true;
			}
			else if (command == "ls")
			{
				t.list(t.head);

			}
			else if (command == "cd" && second != "..")
			{
				t.cd(t.head, second);
			}
			else if (command == "cd" && second == "..")
			{
				t.up(t.head);
			}
			else if (command == "rm" && second != "-rf" && third.length() == 0)
			{
				t.rm(t.head, second);
			}
			else if (command == "rm" && second =="-rf")
			{
				t.rmrf(t.head, third);
			}
			else
			{
				cout << "Command not exist!" << endl;
			}
		}
	} while (!exit);
}


