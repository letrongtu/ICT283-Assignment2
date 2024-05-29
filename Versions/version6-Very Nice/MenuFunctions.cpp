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
         << "3 : Display The Correlation Coefficients of Wind Speed, Air Temperature, and Solar Radiation In A Specified Month." << "\n"
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

void firstCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();
    int month = readMonth();

    Vector<double> windSpeeds;

    if(weather_data.contains(year) && weather_data.at(year).contains(month)){
        weather_data.at(year).at(month).inOrder(accumulateSpeed, windSpeeds);
    }

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    firstCaseOutput(windSpeeds, month, year);
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

//---------------------------------------------------------------------------------

void accumulateSpeed(const WeatherRecord& record, Vector<double>& vector){
    vector.add(record.speed*SpeedExchangeRate);
}

//---------------------------------------------------------------------------------

void firstCaseOutput(const Vector<double>& windSpeeds, int month, int year){
    if (windSpeeds.Size() == 0) {
        outputWindSpeed(0, 0, month, year);
    } else {
        double average = calculateAverage(windSpeeds);
        double stdev = calculateStandardDeviation(windSpeeds);

        outputWindSpeed(average, stdev, month, year);
    }
}

//---------------------------------------------------------------------------------

void secondCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();

    Vector<double> temperatures;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    cout << year << ":" << endl;
    if(weather_data.contains(year)){
        for(int month = 1; month <= MonthCounts; month++){
            if(weather_data.at(year).contains(month)){
                weather_data.at(year).at(month).inOrder(accumulateAirTemp, temperatures);
            }

            secondCaseOutput(temperatures, month, year);
            temperatures.Clear();
        }
    }
    else{
        cout << "No data" << endl;
    }
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

//---------------------------------------------------------------------------------

void accumulateAirTemp(const WeatherRecord& record, Vector<double>& vector){
    vector.add(record.airTemp);
}

//---------------------------------------------------------------------------------

void secondCaseOutput(const Vector<double>& temperatures, int month, int year){
    if (temperatures.Size() == 0) {
        outputAirTemp(0, 0, month);
    } else {
        double average = calculateAverage(temperatures);
        double stdev = calculateStandardDeviation(temperatures);

        outputAirTemp(average, stdev, month);
    }
}

//---------------------------------------------------------------------------------

void thirdCaseHandler(const WeatherLog& weather_data) {
    int month = readMonth();

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    Vector<double> windSpeeds, temperatures, solarRadiations;
    for(Map<int,Map<int, BST<WeatherRecord>>>::const_iterator it = weather_data.begin(); it != weather_data.end(); it++){
        if(it->second.contains(month)){
            it->second.at(month).inOrder(accumulateSpeed, windSpeeds);
            it->second.at(month).inOrder(accumulateAirTemp, temperatures);
            it->second.at(month).inOrder(accumulateSolarRad, solarRadiations);
        }
    }

    double S_T = calculateCorrelationCoef(windSpeeds, temperatures);
    double S_R = calculateCorrelationCoef(windSpeeds, solarRadiations);
    double T_R = calculateCorrelationCoef(temperatures, solarRadiations);

    outputCorrelationCoef(S_T, S_R, T_R, month);
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

//---------------------------------------------------------------------------------

void accumulateSolarRad(const WeatherRecord& record, Vector<double>& vector){
    vector.add(record.solarRad*RadiationExchangeRate);
}

//---------------------------------------------------------------------------------

void fourthCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    ofstream outFile("WindTempSolar.csv");
    if (!outFile) {
        cout << "Error creating file: WindTempSolar.csv" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        return;
    }
    outFile << year << endl;

    Vector<double> windSpeeds, temperatures, solarRadiations;

    if(weather_data.contains(year)){
        for(int month = 1; month <= MonthCounts; month++){
            if(weather_data.at(year).contains(month)){
                weather_data.at(year).at(month).inOrder(accumulateSpeed, windSpeeds);
                weather_data.at(year).at(month).inOrder(accumulateAirTemp, temperatures);
                weather_data.at(year).at(month).inOrder(accumulateSolarRad, solarRadiations);
            }

            fourthCaseOutput(outFile, windSpeeds, temperatures, solarRadiations, month);

            windSpeeds.Clear();
            temperatures.Clear();
            solarRadiations.Clear();
        }
    }
    else{
        outFile << "No data" << endl;
    }

    cout << "Write Data to WindTempSolar.csv Successfully" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    outFile.close();
}

void fourthCaseOutput(ofstream& outFile, const Vector<double>& windSpeeds, const Vector<double>& temperatures, const Vector<double>& solarRadiations, int month){
    if (!(windSpeeds.Size() == 0 && temperatures.Size() == 0 && solarRadiations.Size() == 0)) {
        outFile << MonthsNames[month-1] << "," << fixed << setprecision(1);

        if (windSpeeds.Size() != 0) {
            double avgWindSpeed = calculateAverage(windSpeeds);
            double stdevWindSpeed = calculateStandardDeviation(windSpeeds);
            double madWindSpeed = calculateMAD(windSpeeds);
            outFile << "\"" << avgWindSpeed << "(" << stdevWindSpeed << ", " << madWindSpeed << ")\",";
        } else {
            outFile << ",";
        }

        if (temperatures.Size() != 0) {
            double avgTemperature = calculateAverage(temperatures);
            double stdevTemperature = calculateStandardDeviation(temperatures);
            double madTemperature = calculateMAD(temperatures);
            outFile << "\"" << avgTemperature << "(" << stdevTemperature << ", " << madTemperature << ")\",";
        } else {
            outFile << ",";
        }

        if (solarRadiations.Size() != 0) {
            double totalRadiation = calculateTotal(solarRadiations);
            outFile << totalRadiation << endl;
        } else {
            outFile << "," << endl;
        }
    }
}


//---------------------------------------------------------------------------------
