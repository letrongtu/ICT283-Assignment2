// MenuFunctions.cpp
// Purpose:
// Contains all menu-related functions including displaying the menu, handling choices,...
//
// Version 1 - Trong Tu Le

#include "MenuFunctions.h"
#include "HelperFunctions.h"
#include "OutputFunctions.h"
#include <iostream>
#include <iomanip>

//---------------------------------------------------------------------------------

// Main menu function to display options and process user choices.
void menu(const WeatherLog& weather_data){
    bool exit = false;
    int choice = -1;
    WeatherLog match_data;

    while (!exit){
        showMenu();

        choice = readChoice();

        exit = processChoice(weather_data, choice);
    }
}

//---------------------------------------------------------------------------------

// Function to display the menu options
void showMenu(){
    cout << "Menu: Type(" << "\n"
         << "1 : Display Average Wind Speed And Sample Standard Deviation In A Month Of A Year." << "\n"
         << "2 : Display Average Ambient Air Temperature And Sample Standard Deviation For Each Month Of A Year." << "\n"
         << "3 : Display Total Solar Radiation For Each Month Of A Specified Year." << "\n"
         << "4 : Display Average Wind Speed, Average Ambient Air Temperature, And Total Solar Radiation For Each Month Of A Year." << "\n"
         << "5 : Exit the program.)" << "\n"
         << "-------------------------------------------------------------------------------------------------------------------"
         << endl;
}

//---------------------------------------------------------------------------------

// Function to process user's menu choice and call the appropriate handler.
bool processChoice(const WeatherLog& weather_data, int choice){

    switch(choice){
        case 1:
            firstCaseHandler(weather_data);
            return false;
        case 2:
            secondCaseHandler(weather_data);
            return false;
        case 3:
            thirdCaseHandler(weather_data);
            return false;
        case 4:
            fourthCaseHandler(weather_data);
            return false;
        case 5:
            cout << "Exiting the program..." << endl;
            return true;

        default:
            cout << "Invalid choice. Please enter a choice from 1 to 5!" <<"\n"
                 << "-------------------------------------------------------------------------------------------------------------------" << endl;
            return false;
    }
}

//---------------------------------------------------------------------------------

// Function to calculate and print average wind speed and standard deviation for a specified month and year
void firstCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();
    int month = readMonth();

    Vector<double> windSpeeds;
    for (int i = 0; i < weather_data.Size(); i++) {
        if (weather_data[i].date.GetMonth() == month && weather_data[i].date.GetYear() == year) {
            windSpeeds.add(weather_data[i].speed * SpeedExchangeRate);
        }
    }

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    firstCaseOutput(windSpeeds, month, year);
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

void firstCaseOutput(const Vector<double>& windSpeeds, int month, int year){
    if (windSpeeds.Size() == 0) {
        outputWindSpeed(0, 0, month, year);
    } else {
        double average = calculateAverage(windSpeeds);
        double stdev = calculateStandardDeviation(windSpeeds);

        outputWindSpeed(average, stdev, month, year);
    }
}

// Function to calculate and print average air temperature and standard deviation for each month of a specified year
void secondCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();

    Vector<double> temperatures;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    cout << year << ":" << endl;
    for (int month = 1; month <= MonthCounts; month++) {
        for (int i = 0; i < weather_data.Size(); i++) {
            if (weather_data[i].date.GetMonth() == month && weather_data[i].date.GetYear() == year) {
                temperatures.add(weather_data[i].airTemp);
            }
        }

        secondCaseOutput(temperatures, month, year);
        temperatures.Clear();
    }
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

void secondCaseOutput(const Vector<double>& temperatures, int month, int year){
    if (temperatures.Size() == 0) {
        outputAirTemp(0, 0, month);
    } else {
        double average = calculateAverage(temperatures);
        double stdev = calculateStandardDeviation(temperatures);

        outputAirTemp(average, stdev, month);
    }
}

// Function to calculate and print total solar radiation for each month of a specified year
void thirdCaseHandler(const WeatherLog& weather_data) {
    int month = readMonth();

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    Vector<double> windSpeeds, temperatures, solarRadiations;
    for (int i = 0; i < weather_data.Size(); i++) {
        if (weather_data[i].date.GetMonth() == month) {
            windSpeeds.add(weather_data[i].speed*SpeedExchangeRate);
            temperatures.add(weather_data[i].airTemp);
            solarRadiations.add(weather_data[i].solarRad*RadiationExchangeRate);
        }
    }

    double S_T = calculateCorrelationCoef(windSpeeds, temperatures);
    double S_R = calculateCorrelationCoef(windSpeeds, solarRadiations);
    double T_R = calculateCorrelationCoef(temperatures, solarRadiations);

    outputCorrelationCoef(S_T, S_R, T_R, month);
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

// Function to calculate and write average wind speed, average ambient air temperature, and total solar radiation to a file for each month of a specified year
void fourthCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    ofstream outFile("WindTempSolar.csv");
    if (!outFile) {
        cerr << "Error creating file: WindTempSolar.csv" << endl;
        return;
    }
    outFile << year << endl;

    Vector<double> windSpeeds, temperatures, solarRadiations;
    for (int month = 1; month <= MonthCounts; month++) {

        for (int i = 0; i < weather_data.Size(); i++) {
            if (weather_data[i].date.GetMonth() == month && weather_data[i].date. GetYear() == year) {
                windSpeeds.add(weather_data[i].speed*SpeedExchangeRate);
                temperatures.add(weather_data[i].airTemp);
                solarRadiations.add(weather_data[i].solarRad*RadiationExchangeRate);
            }
        }

        fourthCaseOutput(outFile, windSpeeds, temperatures, solarRadiations, month);
    }

    cout << "Write Data to WindTempSolar.csv Successfully" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    outFile.close();
}

void fourthCaseOutput(ofstream& outFile, const Vector<double>& windSpeeds, const Vector<double>& temperatures, const Vector<double>& solarRadiations, int month){
        if (windSpeeds.Size() == 0 && temperatures.Size() == 0 && solarRadiations.Size() == 0) {
            outFile << MonthsNames[month-1] << ", No Data" << endl;
        } else {
            double avgWindSpeed = calculateAverage(windSpeeds);
            double stdevWindSpeed = calculateStandardDeviation(windSpeeds);
            double avgTemperature = calculateAverage(temperatures);
            double stdevTemperature = calculateStandardDeviation(temperatures);
            double totalRadiation = calculateTotal(solarRadiations);

            outFile << MonthsNames[month-1] << "," << fixed << setprecision(1)
                    << avgWindSpeed << "(" << stdevWindSpeed << "),"
                    << avgTemperature << "(" << stdevTemperature << "),"
                    << totalRadiation << endl;
        }
}

//---------------------------------------------------------------------------------
