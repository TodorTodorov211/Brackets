// StackBrackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// stack is useless

class element
{
public:
	char data;
	element *prev;
};

class Stack
{
	element *end;
	int count;
public:
	Stack()
	{
		end = NULL;
		count = 0;
	}
	void add(char a)
	{
		element *e;
		e = new element;
		e->prev = end;
		end = e;			
		count++;
		e->data = a;
	}
	char pop()
	{
		char res = end->data;
		element *p = end->prev;
		delete end;
		end = p;
		return res;
	}
	bool isEmpty()
	{
		return count == 0;
	}


};

void checkStack(string input)
{
	Stack A;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(' or input[i] == ')')
		{
			A.add(input[i]);
		}
	}
}

void checkString(string input)
{
	int open = 0;
	int close = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			open++;
		}
		else if (input[i] == ')')
		{
			close++;
		}
		if (open < close)
		{
			cout << "Expected a '(' before " << i << endl;
			return;
		}
	}
	if (open != close)
	{
		cout << "Expected more ')' at the end\n";
		return;
	}
	else
	{
		cout << "No mistakes\n";
		return;
	}
}


int main()
{
	string input;
	cin >> input;		//must check
	checkString(input);
    return 0;
}

