// OutputFunctions.cpp
// Purpose:
// Contains all needed output functions
//
// Version 1 - Trong Tu Le

#include "OutputFunctions.h"
#include <iostream>
#include <iomanip>

//---------------------------------------------------------------------------------

// Function to output the average wind speed and standard deviation.
void outputWindSpeed(double avg, double sd, int month, int year){

    cout <<  MonthsNames[month-1] << " " << year << ":";

    if(avg > 0){
        cout << "\nAverage Speed: " << fixed << setprecision(1) << avg << " km/h" << '\n' <<
        "Standard deviation: " << sd << endl;
    }
    else{
        cout << " No data" << endl;
    }
}

//---------------------------------------------------------------------------------

// Function to output the average ambient air temperature, and standard deviation.
void outputAirTemp(double avg, double sd, int month){
    cout << MonthsNames[month-1] << ": ";
    if(avg > 0){
        cout << fixed << setprecision(1) << "average: " << avg << " degrees C, "
                << "stdev: " << sd << endl;
    }
    else{
        cout << " No data" << endl;
    }
}

//---------------------------------------------------------------------------------

// Function to output the total solar radiation, and standard deviation.
void outputSolarRad(double total, int month){
    cout << MonthsNames[month-1] << ": " ;
    if(total > 0){
        cout << fixed << setprecision(1) << total << " kWh/m2" << endl;
    }
    else{
        cout << "No data" << endl;
    }
}

//---------------------------------------------------------------------------------
