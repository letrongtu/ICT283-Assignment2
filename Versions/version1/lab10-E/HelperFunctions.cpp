// HelperFunctions.cpp
// Purpose:
// Contains all functions that do the specified thing
//
// Version 1 - Trong Tu Le

#include "HelperFunctions.h"
#include "Validator.h"
#include <iostream>
#include <string>
#include <cmath>

//---------------------------------------------------------------------------------

// Function to read the choice.
int readChoice(){
    string choice = " ";
    bool valid = false;

    while(!valid){
        cout << "Enter your choice: " << endl;
        cin >> choice;

        valid = isValidNumber(choice);

        if(!valid){
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "!!!Please enter a positive integer!!!" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

    return stoi(choice);
}

//---------------------------------------------------------------------------------

// Function to read the year.
int readYear(){
    string year = " ";
    bool valid = false;

    while(!valid){
        cout << "Enter a year: ";
        cin >> year;

        valid = isValidNumber(year);

        if(!valid){
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "!!!Please enter a positive integer!!!" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        else {
            valid = isValidYear(stoi(year));

            if(!valid){
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "!!!The year must be between 0 to 9999!!!" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        }
    }

    return stoi(year);
}

//---------------------------------------------------------------------------------

// Function to read the month.
int readMonth(){

    string month = " ";
    bool valid = false;

    while(!valid){
        cout << "Enter a month: ";
        cin >> month;

        valid = isValidNumber(month);

        if(!valid){
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "!!!Please enter a positive integer!!!" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        else {
            valid = isValidMonth(stoi(month));

            if(!valid){
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "!!!The month must be between 1 to 12!!!" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    return stoi(month);
}

//---------------------------------------------------------------------------------

// Function to calculate the average of an array
double calculateAverage(const Vector<double>& array) {
    double sum = 0;
    for (int i = 0; i < array.Size(); i++) {
        sum += array[i];
    }

    if(array.Size() == 0){
        return 0;
    }
    else{
        return sum / array.Size();
    }
}

//---------------------------------------------------------------------------------

// Function to calculate the standard deviation of an array
double calculateStandardDeviation(const Vector<double>& array) {
    double mean = calculateAverage(array);
    double sum = calculateSumSquared(array, mean);

    if(array.Size() == 0){
        return 0;
    }
    else{
        return sqrt(sum / array.Size());
    }
}

//---------------------------------------------------------------------------------

// Function to calculate the sum of squared differences from the mean speed.
double calculateSumSquared(const Vector<double>& array, double mean){
    double sum = 0;

    for(LongInt i = 0; i < array.Size(); i++){
        sum += (array[i] - mean) * (array[i] - mean);
    }

    return sum;
}

//---------------------------------------------------------------------------------

// Function to calculate the sum of all elements.
double calculateTotal(const Vector<double>& array){
    double sum = 0;

    for(LongInt i = 0; i < array.Size(); i++){
        sum += array[i];
    }

    return sum;
}

//---------------------------------------------------------------------------------
