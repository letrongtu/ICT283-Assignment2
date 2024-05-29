// TestTime.cpp
//
// Author
// Trong Tu Le
//
// This file is used to test Time class
//----------------------------------------------------------------------------

#include "../time.h"
#include <iostream>

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
    printResult("Test 1", Test1()); // Test the default constructor
    printResult("Test 2", Test2()); // Test the constructor with hour and minute
    printResult("Test 3", Test3()); // Test Setters
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
    Time t1;

    return ((t1.GetHour() == 0 && t1.GetMinute() == 0) ? 1 : 0);
}

//----------------------------------------------------------------------------

// Test the constructor with hour and minute
int Test2(){
    Time t2(12, 34);

    return ((t2.GetHour() == 12 && t2.GetMinute() == 34) ? 1 : 0);
}

//----------------------------------------------------------------------------

// Test Setters
int Test3(){
    Time t3;

    t3.SetHour(12);
    t3.SetMinute(59);

    return ((t3.GetHour() == 12 && t3.GetMinute() == 59) ? 1 : 0);
}

//----------------------------------------------------------------------------

// Test Getters
int Test4(){
    Time t4(9, 8);

    return ((t4.GetHour() == 9 && t4.GetMinute() == 8) ? 1 : 0);
}
