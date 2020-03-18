/******************************************************************************
 *
 *  PROGRAM: PASSWORD STRENGTH
 *
 *  AUTHOR:  Osvaldo Carrillo
 *
 * SUMMARY: This program analyze the strength of a given user password. The 
 *          program will return the number of guesses it will take the crack
*           the password. The program also computes the bit strength of a 
*           password.
 ******************************************************************************/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int lettersLowerCase = 26;
const int lettersUpperCase = 26;
const int digits = 10;
const int symbols = 32;

int numberOfCombinations(char * password);
void bitStrength(int cases, char* password);

int main()
{

    char* password = new char[1024];
    cout << "Please enter the password:";
    cin >> password;
    int cases = numberOfCombinations(password);
    bitStrength(cases, password);
    delete[] password;
    return 0;
}



/******************************************************************************
 * NUMBER OF COMBINATIONS
 * This function returns all the possible combinations for the given password.
 ******************************************************************************/
int numberOfCombinations(char * password) {
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

    long long int powerResult = pow(cases, lengthOfPassword/*Exp*/);
    cout << "There are " << powerResult << " combinations" << endl;


    return cases;
}

/******************************************************************************
 * BIT STRENGTH
 * This function determines the bit strength of the given password. 
 ******************************************************************************/
void bitStrength(int cases, char * password) {

    int m = strlen(password); //Length of string
    int result = log2(pow(cases, m /*Exp*/));
    cout << "That is equivalent to a key of " << result << " bits" << endl;
}