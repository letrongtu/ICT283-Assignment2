// TestValidateFunctions.cpp
//
// Author
// Trong Tu Le
//
// This file is used to test validate functions
//---------------------------------------------------------------------------------
#include "../HelperFunctions.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
//---------------------------------------------------------------------------------
// Function declarations

void printResult(string testName, bool result);
int testCalculateTotal();
int testCalculateAverage();
int testCalculateSumSquared();
int testCalculateSDevi();

//---------------------------------------------------------------------------------

int main() {

    //--------------------------------------
    //Test calculateTotal
    printResult("testCalculateTotal", testCalculateTotal());

    //--------------------------------------
    //Test calculateAverage
    printResult("testCalculateAverage", testCalculateAverage());

    //--------------------------------------
    //Test calculateSumSquared
    printResult("testCalculateSumSquared", testCalculateSumSquared());

    //--------------------------------------
    //Test calculateSDevi
    printResult("testCalculateSDevi", testCalculateSDevi());

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
//Test calculateTotal function
int testCalculateTotal(){
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double sum = calculateTotal(array, 5);

    return (fabs(sum - 16.5) < 0.05 ? 1 : 0);
}

//---------------------------------------------------------------------------------

//Test calculateAverage function
int testCalculateAverage(){
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    double avg = calculateAverage(array, 5);

    return (fabs(avg - 3.3) < 0.05 ? 1 : 0);
}

//---------------------------------------------------------------------------------

//Test calculateSumSquared function
int testCalculateSumSquared(){
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    double avg = calculateAverage(array, 5);

    double sum = calculateSumSquared(array, avg, 5);

    return (fabs(sum - 12.1) < 0.05 ? 1 : 0);
}

//---------------------------------------------------------------------------------

//Test calculateSDevi function
int testCalculateSDevi(){
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    double avg = calculateAverage(array, 5);

    double sd = calculateSDevi(array, avg, 5);

    return (fabs(sd - 1.55) < 0.05 ? 1 : 0);
}

//---------------------------------------------------------------------------------


