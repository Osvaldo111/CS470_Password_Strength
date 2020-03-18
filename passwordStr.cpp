/******************************************************************************
 *
 *  PROGRAM: bed.cpp
 *
 *  AUTHOR:  J. Matt Pontius
 *
 * SUMMARY: Compiles and tests user specified source code files according to the
 *          user's predefined test instructions file.  Results of the test are
 *          output to the screen and, optionally, to files if this program is
 *          run in * "grade mode".
 *
 ******************************************************************************/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int lettersLowerCase = 26;
const int lettersUpperCase = 26;
const int digits = 10;
const int symbols = 32;


void numberOfCombinations(char * password);
int main()
{

    char* password = new char[1024];
    cout << "Please enter the password:";
    cin >> password;
    numberOfCombinations(password);
    delete[] password;
    return 0;
}

void numberOfCombinations(char * password) {
    const string  isNotSpecialChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890";
    int lengthOfPassword = strlen(password);
    int cases = 0;

    string passwordStr(password);
    if (string::npos != passwordStr.find_first_of("0123456789"))
    {
        //cout << "digit(s)found!" << std::endl;
        cases += digits;
    }

    if (any_of(passwordStr.begin(), passwordStr.end(), islower)) { // all lowercase

        //cout << "Lower Case" << std::endl;
        cases += lettersLowerCase;
    }

    if (any_of(passwordStr.begin(), passwordStr.end(), isupper)) { // all lowercase

        //cout << "Upper Case" << std::endl;
        cases += lettersUpperCase;
    }

    if (string::npos != passwordStr.find_first_not_of(isNotSpecialChar)) {
        //cout << "Special character" << std::endl;
        cases += symbols;
    }

    //cout << "Total cases: " << cases << endl;
    //cout << "Password: " << passwordStr << endl << "Length: " <<   lengthOfPassword <<endl;
    cout << "There are " << pow(cases, lengthOfPassword/*Exp*/) << " combinations" << endl;
}
