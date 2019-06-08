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
 *       the stack rather than using traditional contructs such as
 *        parameters and variables
 *
 ************************************************************************/

#include <stdlib.h>        // for malloc()
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

void partOne(int); // Display the address of the stack, the heap, and the code segments
void partTwo(char *, long); // Display the contents of the stack in a (somewhat) easy to
// understand format
void partThree(); // Demonstrate mastery of stack by mipulating data on
// the stack

int main()
{
    char text[] = "%%main%%";
    long number = 1234567;
    &number;
    
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

void partOne (int byValueParameter)
{
    void *pStack = NULL;
    void *pHeap = NULL;
    const void *pCode = NULL;
    
    pStack = &pStack;
    
    pHeap = new int;
    
    pCode = (void*)&partOne;
    
    cout << "Stack: " << pStack << endl;
    cout << "Heap:  " << pHeap << endl;
    cout << "Code:  " << pCode << endl;
    
    return;
}

string displayCharArray(const char * p)
{
    string output;
    for (int i = 0; i < 8; i++)
        output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
    return output;
}

void partTwo (char *text, long number)
{
    long bow = number + 1111111;
    
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
        cout << "[" << setw(2) << i << "]";
        
        cout << setw(15) << &bow +i;
        
        cout << setw(20) << hex << (&bow)[i];
        
        cout << setw(20) << dec << (&bow)[i];
        
        char * charString = reinterpret_cast < char * > (&bow + i);
        cout << setw(20) << displayCharArray(charString) << endl;
    }
}


void fail(char grade);
void pass(char grade);

void readStack()
{
    int number;
    char text[16];
    
    int p = 42;
    
    for (int i = 20; i <= 40; i++)
    {
        cerr << "[" << setw(4) << i << "]";
        
        cerr << setw(20) << dec << (&p)[i];
        
        char * c = reinterpret_cast < char * > (&p + i);
        string output;
        for (int i = 0; i < 4; i++)
        {
            output += string(" ") + (c[i] >= ' ' && c[i] <= 'z' ? c[i] : '.');
        }
        
        cerr << setw(10) << output << endl;
    }
    
    number = * (&p + 33);
    
    for (int i = 0; i < 16; i++)
    {
        text[i] = * (((char*)(&p + 29)) + i);
    }
    
    * (int*)(&p + 35) = (size_t) &pass;
    
    * (((char *)(&p + 34) + 3)) = 'A';
    
    
    cout << "\tnumber: "
    << number
    << endl;
    cout << "\ttext:   "
    << text
    <<endl;
    return;
}


void partThree()
{
    int number;
    char text[16];
    
    char letterGrade;
    void (*pointerFunction)(char);
    
    cout << "number: ";
    cin  >> number;
    cout << "text:   ";
    cin  >> text;
    
    pointerFunction = fail;
    letterGrade = 'B';
    
    readStack();
    (*pointerFunction)(letterGrade);
    
    return;
}


void fail(char grade)
{
    cout << "\tI am sorry, but you got a 'F'\n";
}

void pass(char grade)
{
    cout << "\tGood job, you got a(n) '" << grade << "'\n";
}
