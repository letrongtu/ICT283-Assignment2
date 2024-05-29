// TestValidateFunctions.cpp
//
// Author
// Trong Tu Le
//
// This file is used to test validate functions
//---------------------------------------------------------------------------------
#include "../Validator.h"
#include <iostream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------------
// Function declarations

void printResult(string testName, bool result);
int testIsValidInteger();
int testIsValidYear();
int testIsValidMonth();


//---------------------------------------------------------------------------------

int main() {

    //--------------------------------------
    //Test isValidYear
    printResult("testIsValidInteger", testIsValidInteger());

    //--------------------------------------
    //Test isValidYear
    printResult("testIsValidYear", testIsValidYear());

    //--------------------------------------
    //Test isValidMonth
    printResult("testIsValidMonth", testIsValidMonth());

    //--------------------------------------

    cout << "All tests passed" << endl;

    return(0);
}

//---------------------------------------------------------------------------------
// Function to print the result of the test
void printResult(string testName, bool result){
    string stringResult = result ? "Passed" : "Failed";

    cout << "\"" << testName << "\"" << " " << stringResult << ".\n" << endl;
}

//---------------------------------------------------------------------------------

//Test isValidYear function
int testIsValidInteger(){
    string s1 = "abc";
    string s2 = "212";

    return (!isValidInteger(s1) && isValidInteger(s2) ? 1 : 0);
}

//---------------------------------------------------------------------------------

//Test isValidYear function
int testIsValidYear(){
    int y1 = 0;
    int y2 = -1;
    int y3 = 2914;
    int y4 = 10000;

    return(isValidYear(y1) && !isValidYear(y2) && isValidYear(y3) && !isValidYear(y4) ? 1 : 0);
}

//---------------------------------------------------------------------------------

//Test isValidMonth function
int testIsValidMonth(){
    int m1 = 0;
    int m2 = 9;
    int m3 = 13;

    return(!isValidMonth(m1) && isValidMonth(m2) && !isValidMonth(m3) ? 1 : 0);
}

//---------------------------------------------------------------------------------
