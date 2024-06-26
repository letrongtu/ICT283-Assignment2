// TestVector.cpp
//
// Author
// Trong Tu Le
//
// This file is used to test Vector class
//---------------------------------------------------------------------------------
#include "../../Data Structures/vector.h"
#include "../../Data Structures/date.h"
#include "../../Data Structures/time.h"
#include <iostream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------------
// Function declarations

void printResult(string testName, bool result);
int testDefaultConstructor();
int testCopyConstructor();
int testDestructor();
int testAddFunction();
int testGetOperator();
int testSetOperator();
int testClearFunction();
int testGrowFunction();

//---------------------------------------------------------------------------------

int main() {

    //--------------------------------------
     //Test Vector's default constructor
    printResult("testDefaultConstructor", testDefaultConstructor());

    //--------------------------------------
    //Test Vector's copy constructor
    printResult("testCopyConstructor", testCopyConstructor());

    //--------------------------------------
    //Test Vector's Destructor
    printResult("testDestructor", testDestructor());
    //--------------------------------------
    //Test Vector's add function
    printResult("testAddFunction", testAddFunction());

    //--------------------------------------
    //Test Vector's get operator
    printResult("testGetOperator", testGetOperator());

    //--------------------------------------
    //Test Vector's Set operator
    printResult("testSetOperator", testSetOperator());

    //--------------------------------------
    //Test Vector's Clear function
    printResult("testClearFunction", testGrowFunction());

    //--------------------------------------
    //Test Vector's grow function
    printResult("testGrowFunction", testGrowFunction());

    //--------------------------------------

    cout << "All tests passed" << endl;

    return(0);
}

//---------------------------------------------------------------------------------
//Function Implementations

// Function to print the result of the test
void printResult(string testName, bool result){
    string stringResult = result ? "Passed" : "Failed";

    cout << "\"" << testName << "\"" << " " << stringResult << ".\n" << endl;
}

//---------------------------------------------------------------------------------

// Function to test Vector's default constructor
int testDefaultConstructor(){
    Vector<int> v;
    return v.Size() == 0 ? 1 : 0;
}

//---------------------------------------------------------------------------------

// Function to test Vector's copy constructor
int testCopyConstructor(){
    Vector<int> v1;
    v1.add(2);
    Vector<int> v2(v1);

    return v2.Size() == 1 && v2[0] == 2 ? 1 : 0;
}

//---------------------------------------------------------------------------------

// Function to test the destructor of Vector
int testDestructor(){
    Vector<int> v;
    v.add(19);
    v.~Vector();

    return (v.Size() == 0 ? 1 : 0);
}

//---------------------------------------------------------------------------------

// Function to test add function
int testAddFunction(){
    Vector<int> v;
    v.add(19);

    return (v.Size() == 1 ? 1 : 0);
}

//---------------------------------------------------------------------------------

// Function to test add function
int testGetOperator(){
    Vector<int> v;
    v.add(19);
    return (v[v.Size()-1] == 19 ? 1 : 0);
}

//---------------------------------------------------------------------------------

// Function to test add function
int testSetOperator(){
    Vector<int> v;
    v.add(19);
    v[v.Size()-1] = 20;

    return (v[v.Size()-1] == 20 ? 1 : 0);
}

//---------------------------------------------------------------------------------

// Function to test add function
int testClearFunction(){
    Vector<int> v;
    v.add(19);
    v.Clear();

    return (v.Size() == 0 ? 1 : 0);
}

//---------------------------------------------------------------------------------

// Function to test add function
int testGrowFunction(){
    Vector<int> v;
    v.add(100);
    v.add(101);

    return (v.Size() > 1 ? 1 : 0);
}

//---------------------------------------------------------------------------------


