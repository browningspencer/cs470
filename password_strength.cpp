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
#include <regex>
#include <math.h>
using namespace std;

int main() {
    string password;
    int alphabetSize = 0;
    int passwordLength = 0;
    
    cout << "Please enter the password: ";
    cin >> password;
    passwordLength = password.size();
    
    // Numbers
    std::tr1::regex rNum("[\\[0-9]");
    if (std::tr1::regex_search(password, rNum)) {
        alphabetSize += 10;
    }
    
    // Lowercase
    regex rLower("[\\[a-z]");
    if (regex_search(password, rLower)) {
        alphabetSize += 26;
    }
    
    // Uppercase
    regex rUpper("[\\[A-Z]");
    if (regex_search(password, rUpper)) {
        alphabetSize += 26;
    }
    
    // Special Characters
    std::regex rSpecial("[^a-zA-Z0-9\s]");
    if (regex_search(password, rSpecial)) {
        alphabetSize +=32;
    }
    
    int combinations = pow(alphabetSize, passwordLength);
    int bits = log2(combinations);
    
    cout << alphabetSize << endl;
    cout << passwordLength << endl;
    
    cout << "There are " << combinations << " combinations" << endl;
    cout << "That is equivalent to a key of " << bits << " bits" << endl;
    
    return 0;
}
