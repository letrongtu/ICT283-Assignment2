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

// Function to calculate the correlation coefficient
double calculateCorrelationCoef(const Vector<double>& array1, const Vector<double>& array2){
    if(array1.Size() != array2.Size()){
        return -1;
    }

    double array1Avg = calculateAverage(array1);
    double array2Avg = calculateAverage(array2);

    double numerator = 0;
    double sumX = 0;
    double sumY = 0;

    for(int i = 0; i < array1.Size(); i++){
        numerator += (array1[i] - array1Avg) * (array2[i] - array2Avg);
        sumX += (array1[i] - array1Avg) * (array1[i] - array1Avg);
        sumY += (array2[i] - array2Avg) * (array2[i] - array2Avg);
    }

    double denominator = sqrt(sumX * sumY);

    return numerator/denominator;
}

//---------------------------------------------------------------------------------
// Function to calculate the mean absolute deviation
double calculateMAD(const Vector<double>&array){
    double avg = calculateAverage(array);

    double sum = 0;
    for(int i = 0; i < array.Size(); i++){
        sum += fabs(array[i] - avg);
    }

    return sum/array.Size();
}

//---------------------------------------------------------------------------------