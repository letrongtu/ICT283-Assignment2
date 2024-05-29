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

// Function to output the correlation coefficent of wind speed, air temp, and solar radiation
void outputCorrelationCoef(double s_t, double s_r, double t_r, int month){
    cout << "Sample Pearson Correlation Coeffient for " << MonthsNames[month-1] << ": " << endl;
    cout << "S_T: " << fixed << setprecision(2) << s_t << endl;
    cout << "S_R: " << s_r << endl;
    cout << "T_R: " << t_r << endl;
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
