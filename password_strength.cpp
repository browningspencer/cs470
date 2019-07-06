/***********************************************************************
 * Program:
 *    Lab 11, Password Strength
 *    Brother Wilson, CS470
 * Author:
 *    Spencer Browning
 * Summary:
 *    Please include a detailed description of:
 *    1. What this program is designed to do
 *    2. How this program will go about solving the problem
 *    3. What assumptions about input (file or user) is made
 *    4. Citations if the algorithm was borrowed or inspired from any source
 ************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

string userInput();
double calculateCombinations(string password);
int calculateBits(double combinations);
int calculateAlphabetSize(string password);
void output(double combinations, int bits);

int main()
{
    string input = userInput();
    
    double combinations = calculateCombinations(input);
    
    int bits = calculateBits(combinations);
    
    output(combinations, bits);
    
    return 0;
}

/*********************************************
 * userInput
 *********************************************/

string userInput ()
{
    string password;
    
    cout << "Please enter the password: ";
    cin >> password;
    
    return password;
}

/*********************************************
 * calculateCombinations
 * calculates number of combinations; equating
 * to the number of guesses to crack the password
 *********************************************/
double calculateCombinations(string password)
{
    int passwordLength = password.length();
    
    int alphabetSize = calculateAlphabetSize(password);
    
    double combinations = pow(alphabetSize, passwordLength);
    
    return combinations;
}

/*********************************************
 * calculateAlphabetSize
 * calculates possible characters based on char
 * types in the password (number, uppercase
 * letter, lowercase letter, or symbol)
 *********************************************/
int calculateAlphabetSize(string password)
{
    int alphabetSize = 0;
    
    // Checks for the four types
    bool foundNumber = false;
    bool foundLowerCase = false;
    bool foundUpperCase = false;
    bool foundSymbol = false;
    
    char iterator = 'a';
    
    // iterating through each char in password string
    for (int i = 0; i < password.length(); i++) {
        iterator = password[i];
        if (ispunct(iterator)) {
            if (foundSymbol)
                continue;
            
            alphabetSize += 32;
            foundSymbol = true;
        }
        
        if (isdigit(iterator)) {
            if (foundNumber)
                continue;
            
            alphabetSize += 10;
            foundNumber = true;
        }
        
        if (isupper(iterator)) {
            if (foundUpperCase)
                continue;
            
            alphabetSize += 26;
            foundUpperCase = true;
        }
        
        if (islower(iterator)) {
            if (foundLowerCase)
                continue;
            
            alphabetSize += 26;
            foundLowerCase = true;
        }
    }
    
    return alphabetSize;
}

/*********************************************
 * calculateBits
 * calculates bit strength
 *********************************************/
int calculateBits(double combinations)
{
    int bits = (int)log2(combinations);
    
    return bits;
}

/*********************************************
 * Output
 *********************************************/
void output(double combinations, int bits)
{
    cout.setf(ios::fixed);
    
    cout << "There are " << setprecision(0) << combinations << " combinations" << endl;
    cout << "That is equivalent to a key of " << bits << " bits" << endl;
}
