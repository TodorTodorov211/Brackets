// BracketsComplex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void checkString(string input)
{
	int opensml = 0;
	int closesml = 0;
	int openmid = 0;
	int closemid = 0;
	int openbig = 0;
	int closebig = 0;
	int mistakes = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			opensml++;
		}
		else if (input[i] == ')')
		{
			closesml++;
		}
		else if (input[i] == '[')
		{

			openmid++;
			if (closesml != opensml)
			{
				cout << "Expected more ')' before " << i << endl;
				mistakes++;
			}
			
			opensml = 0;
			closesml = 0;
		}
		else if (input[i] == ']')
		{
			closemid++;
			if (opensml == 0 or closesml == 0)
			{
				cout << "Invalid use of '[]' at " << i << endl;
				mistakes++;
			}
			if (closesml != opensml)
			{
				cout << "Expected more ')' before " << i << endl;
				mistakes++;
			}
			opensml = 0;
			closesml = 0;
		}
		else if (input[i] == '{')
		{
			openbig++;
			if (closesml != opensml)
			{
				cout << "Expected more ')' before " << i << endl;
				mistakes++;
			}
			opensml = 0;
			closesml = 0;

			if (closemid != openmid)
			{
				cout << "Expected more ']' before " << i << endl;
				mistakes++;
			}
			openmid = 0;
			closemid = 0;
		}
		else if (input[i] == '}')
		{
			closebig++;
			if (closesml != opensml)
			{
				cout << "Expected more ')' before " << i << endl;
				mistakes++;
			}
			/*if (opensml == 0 or closesml == 0)
			{
				cout << "Invalid use of '[]' at " << i << endl;
				mistakes++;
			}
			*/
			opensml = 0;
			closesml = 0;

			if (closemid != openmid)
			{
				cout << "Expected more ']' before " << i << endl;
				mistakes++;
			}
			if (openmid == 0 or closemid == 0)
			{
				cout << "Invalid use of '{}' at " << i << endl;
				mistakes++;
			}
			openmid = 0;
			closemid = 0;
		}
		if (closesml > opensml)
		{
			cout << "Expected '(' before " << i << endl;
			mistakes++;
		}
		else if (openmid < closemid)
		{
			cout << "Expected '[' before " << i << endl;
			mistakes++;
		}
		else if (openbig < closebig)
		{
			cout << "Expected '{' before " << i << endl;
			mistakes++;
		}
	}
	if (opensml != closesml)
	{
		cout << "Expected more ')' at the end\n";
		mistakes++;
	}
	else if (openmid != closemid)
	{
		cout << "Expected more ']' at the end\n";
		mistakes++;
	}
	else if (openbig != closebig)
	{
		cout << "Expected more '}' at the end\n";
		mistakes++;
	}
	
	
	cout << "Mistakes: " << mistakes << endl;
	
	return;
}

int main()
{
	string input;
	cin >> input;
	checkString(input);
    return 0;
}

