// TestDate.cpp
//
// Author
// Trong Tu Le
//
// This file is used to test Vector class

//----------------------------------------------------------------------------
#include "../../Data Structures/date.h"
#include "../../Data Structures/date.cpp"
#include <iostream>

//----------------------------------------------------------------------------

using namespace std;

//----------------------------------------------------------------------------
// Function declarations

void printResult(string testName, bool result);
int Test1();
int Test2();
int Test3();
int Test4();

//----------------------------------------------------------------------------

int main(){
    printResult("Test 1", Test1()); // Test the default constructor and << operator
    printResult("Test 2", Test2()); // Test the constructor with hour and minute and << operator
    printResult("Test 3", Test3()); // Test Setters and << operator
    printResult("Test 4", Test4()); // Test Getters

    cout << "All passed" << endl;

    return(0);
}

//----------------------------------------------------------------------------
// Function Implementations

// Function to print the result of the test
void printResult(string testName, bool result){
    string stringResult = result ? "Passed" : "Failed";

    cout << "\"" << testName << "\"" << " " << stringResult << ".\n" << endl;
}

//----------------------------------------------------------------------------

// Test the default constructor
int Test1(){
    Date d1;

    return ((d1.GetDate() == 0 && d1.GetMonth() == 0 && d1.GetYear() == 0) ? 1 : 0);
}

//----------------------------------------------------------------------------

// Test the constructor with hour and minute
int Test2(){
    Date d2(18, 4, 2003);

    return ((d2.GetDate() == 18 && d2.GetMonth() == 4 && d2.GetYear() == 2003) ? 1 : 0);
}

//----------------------------------------------------------------------------

// Test Setters
int Test3(){
    Date d3;

    d3.SetDate(18);
    d3.SetMonth(4);
    d3.SetYear(2003);

    return ((d3.GetDate() == 18 && d3.GetMonth() == 4 && d3.GetYear() == 2003) ? 1 : 0);
}

//----------------------------------------------------------------------------

// Test Getters
int Test4(){
    Date d4(12, 03, 2003);

    return ((d4.GetDate() == 12 && d4.GetMonth() == 3 && d4.GetYear() == 2003) ? 1 : 0);
}
