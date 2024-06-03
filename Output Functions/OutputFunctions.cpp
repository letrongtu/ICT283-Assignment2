// OutputFunctions.cpp
// Purpose: Contains all needed output functions
//
// Version 1 - Trong Tu Le
//---------------------------------------------------------------------------------

#include "OutputFunctions.h"
#include <iostream>
#include <iomanip>

//---------------------------------------------------------------------------------

// Function to output the average wind speed and standard deviation.
void outputWindSpeed(double avg, double sd, int month, int year) {
    std::cout << MonthsNames[month-1] << " " << year << ":";

    if (avg > 0) {
        std::cout << "\nAverage Speed: " << std::fixed << std::setprecision(1) << avg << " km/h" << '\n' <<
        "Standard deviation: " << sd << std::endl;
    } else {
        std::cout << " No data" << std::endl;
    }
}

//---------------------------------------------------------------------------------

// Function to output the average ambient air temperature, and standard deviation.
void outputAirTemp(double avg, double sd, int month) {
    std::cout << MonthsNames[month-1] << ": ";
    if (avg > 0) {
        std::cout << std::fixed << std::setprecision(1) << "average: " << avg << " degrees C, "
                << "stdev: " << sd << std::endl;
    } else {
        std::cout << " No data" << std::endl;
    }
}

//---------------------------------------------------------------------------------

// Function to output the correlation coefficient of wind speed, air temp, and solar radiation
void outputCorrelationCoef(double s_t, double s_r, double t_r, int month) {
    std::cout << "Sample Pearson Correlation Coefficient for " << MonthsNames[month-1] << ": " << std::endl;
    std::cout << "S_T: " << std::fixed << std::setprecision(2) << s_t << std::endl;
    std::cout << "S_R: " << s_r << std::endl;
    std::cout << "T_R: " << t_r << std::endl;
}

//---------------------------------------------------------------------------------
