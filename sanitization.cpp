//
// main.cpp
// lab05
//
//  Created by Spencer Browning on 6/1/19.
//  Copyright © 2019 Spencer Browning. All rights reserved.
//

/*******************************
* CS 470
* Sanitization Lab
* Week 06
* 
* Author: Spencer Browning
*
*******************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void sanitize(string &input, int &location)
{
	int temp = location - 1;

	input.replace(temp, 1, "&lt;");

	while (input[temp] != '>' || temp >= input.length()) 
	{
		temp++;
	}
	input.replace(temp, 1, "&gt;");
}

bool nested(string temp, stack<string> &nestStack) 
{
	if (temp[0] == '/')
	{
		temp.erase(0, 1);
		if (nestStack.top() != temp) 
		{
			return false;
		} else {
			nestStack.pop();
			return true;
		}
	} else {
		nestStack.push(temp);
		return true;
	}
}

string whiteList()
{
	int location = 0;
	bool good = false;
	string temp = "";
	
	string whiteList[13] = { "a", "abbr", "acronym", "b", "blockquote", "cite",
							"code", "del", "em", "i", "q", "strike", "strong"};

	stack<string> nestStack;
	string input = "";

	cout << "> ";

	getline(cin, input);
	while (location != -1) 
	{
		location = input.find('<', location);

		if (location != -1) {
			temp = "";
			
			for (int i = ++location; input[i] != '>'; i++)
			{
				if (input[i] == ' ')
					break;
				temp += input[i];
			}

			for (int i = 0; i < 13; i++)
			{
				if (temp == whiteList[i] || temp == ('/' + whiteList[i]))
				{
					good = true;
				}
			}

			if (!good) 
			{
				sanitize(input, location);
			} else {
				if (!nested(temp, nestStack))
				{
					sanitize(input, location);
				}
				good = false;
			}
		}
	}

	while (!nestStack.empty())
	{
		input += ("</" + nestStack.top() + ">");
		nestStack.pop();
	}
	return input;
}

int main() 
{
	string sanitize;

	while (sanitize != "quit") {
		sanitize = whiteList();
		cout << "\t" << sanitize << "\n";
	}
	return 0;
}
