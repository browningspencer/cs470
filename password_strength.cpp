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
    int strength = 0;
    int passwordLength = 0;
    
    cout << "Please enter password: ";
    cin >> password;
    passwordLength = password.size();
    
    // Numbers
    regex rNum("[\\[0-9]");
    if (regex_search(password, rNum))
        strength += 10;
    
    // Lowercase
    regex rLower("[\\[a-z]");
    if (regex_search(password, rLower))
        strength += 26;
    
    // Uppercase
    regex rUpper("[\\[A-Z]");
    if (regex_search(password, rUpper))
        strength += 26;
    
    // Special Characters
    regex rSpecial("[^[:alnum:]]");
    if (regex_search(password, rSpecial))
        strength +=32;
        
    int combinations = pow(strength, passwordLength);
    int bits = log2(combinations);
    
    cout << "There are " << combinations << " number of unique combinations." << endl;
    cout << "That amounts to a key of " << bits << " bits" << endl;
    
    return 0;
}
