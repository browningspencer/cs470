/***********************************************************************
* Program:
*    Lab 07, Stack Manipulation
*    Brother Wilson, CS470
* Author:
*    Spencer Browning
* Summary:
*    1) Display the address of the stack, the heap, and the code
*        segments
*      2) Display the contents of the stack in a (somewhat) easy to
*         understand format
*    3) Demonstrate your mastery of the stack by manipulating data on
*       the stack rather than using traditional constructs such as
*        parameters and variables
*
************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

void partOne(int); // Display the address of the stack, the heap, and 
// the code segments
void partTwo(char *, long); // Display the contents of the stack in 
// a (somewhat) easy to understand format
void partThree(); // Demonstrate mastery of stack by manipulating data on
// the stack

/******************************************************
* MAIN
* This function will only take you to one of the three parts
* of Assignment 05
*****************************************************/
int main()
{
	char text[] = "%%main%%";
	long number = 1234567;
	&number;

	// prompt
	cout << "Please select an option:\n";
	cout << "  1.  Find the address\n";
	cout << "  2.  Display the contents of the stack\n";
	cout << "  3.  Manipulate the stack\n";
	cout << "> ";

	int selection;
	cin >> selection;

	switch (selection)
	{
		case 1:
		partOne(1);
		break;
		case 2:
		partTwo(text, number + 1111111);
		break;
		case 3:
		partThree();
		break;
		default:
		cout << "Unknown option\n";
		return 1;
	}

	return 0;
}

/**************************************************************
**************************************************************
**************************** PART 1 **************************
**************************************************************
**************************************************************/

/**********************************************
* Part 1
*
* Find the address of the stack, heap, and code.
* Note that it will be in a different location with
* every execution
**********************************************/
void partOne (int byValueParameter)
{
	void *pStack = NULL;
	void *pHeap = NULL;
	const void *pCode = NULL;

	////////////////////////////////////////////////
	// put your magic code between here...

	// get the address of the stack
	pStack = &pStack;

	// DERFERENCE for heap
	pHeap = new int;

	// pull from function to show code
	pCode = (void*) & partOne;

	// ... and here
	////////////////////////////////////////////////

	cout << "Stack: " << pStack << endl;
	cout << "Heap:  " << pHeap << endl;
	cout << "Code:  " << pCode << endl;

	return;
}

/**************************************************************
**************************************************************
**************************** PART 2 **************************
**************************************************************
**************************************************************/

/************************************************
* CONVERT TO STRING
* Convert the data from p into a human-readable string
* by removing all the unprintable characters and replacing
* them with a dot
***********************************************/
string displayCharArray(const char * p)
{
	string output;
	for (int i = 0; i < 8; i++)
		output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
	return output;
}

/*************************************************
* PART 2
*
* Display the contents of the stack. This will be from
* slot -4 to slot 20.
*************************************************/
void partTwo (char *text, long number)
{
	// start your display of the stack from this point
	long bow = number + 1111111;

	// header for our table. Use these setw() offsets in your table
	cout << "[" << setw(2) << 'i' << ']'
	<< setw(15) << "address"
	<< setw(20) << "hexadecimal"
	<< setw(20) << "decimal"
	<< setw(18) << "characters"
	<< endl;
	cout << "----+"
	<< "---------------+"
	<< "-------------------+"
	<< "-------------------+"
	<< "-----------------+\n";

	for (int i = -4; i <= 20; i++)
	{
	////////////////////////////////////////////////
	// put your magic code between here...

	// display the number
		cout << "[" << setw(2) << i << "]";

	// display the address of bow in relation to i
		cout << setw(15) << &bow + i;

	// display the hex value
		cout << setw(20) << hex << (&bow)[i];

	// display the decimal value
		cout << setw(20) << dec << (&bow)[i];

	// get and display char stuff
		char * charString = reinterpretCast < char * > (&bow + i);
		cout << setw(20) << displayCharArray(charString) << endl;
	// ... and here
	////////////////////////////////////////////////
	}
}

/**************************************************************
**************************************************************
**************************** PART 3 **************************
**************************************************************
**************************************************************/


void fail(char grade);
void pass(char grade);

/**********************************************************************
* All your code needs to exist in this function below the comment
*********************************************************************/
void readStack()
{
	int number;
	char text[16];

	////////////////////////////////////////////////
	// put your magic code between here...

	// variable to find memory locations, also the answer to everything
	int p = 42;

	// loop through 20 memory locations and display char and int
	// to find the offset for values to receive and change
	for (int i = 20; i <= 40; i++)
	{
	// display the number
		cerr << "[" << setw(4) << i << "]";
	// display the decimal value
		cerr << setw(20) << dec << (&p)[i];
	// get and display char stuff
		char * c = reinterpretCast < char * > (&p + i);
		string output;
		for (int i = 0; i < 4; i++)
		{
			output += string(" ") + (c[i] >= ' ' && c[i] <= 'z' ? c[i] : '.');
		}

		cerr << setw(10) << output << endl;
	}
	// get the number
	number = * (&p + 33);

	// get the text
	for (int i = 0; i < 16; i++)
	{
		text[i] = * (((char*)(&p + 29)) + i);
	}

	* (int*)(&p + 35) = (size t) &pass;

	* (((char *)(&p + 34) + 3)) = 'A';


	// ... and here
	////////////////////////////////////////////////

	// output the goods
	cout << "\tnumber: "
	<< number
	<< endl;
	cout << "\ttext:   "
	<< text
	<< endl;
	return;
}

/*******************************************************************
* Part 3
*
* This function contains the data that you are trying to manipulate.
* Please don't modify partTwo() in any way
********************************************************************/
void partThree()
{
	int number;	   // first local variable that you need to read
	char text[16]; // second

	char letterGrade;
	void (*pointerFunction)(char);

	// get the values
	cout << "number: ";
	cin  >> number;
	cout << "text:   ";
	cin  >> text;

	// Call the function and display the results.
	pointerFunction = fail;
	letterGrade = 'B';

	readStack();			// vulnerability is here
	(*pointerFunction)(letterGrade);

	return;
}

/**********************************************************************
* The failure case. Don't touch this function
*********************************************************************/
void fail(char grade)
{
	cout << "\tI am sorry, but you got a F\n";
}

/**********************************************************************
* I think you would really rather call this function.  This
* is read-only also
*********************************************************************/
void pass(char grade)
{
	cout << "\tGood job, you got a(n) '" << grade << "'\n";
}
