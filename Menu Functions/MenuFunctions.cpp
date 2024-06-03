// MenuFunctions.cpp
// Purpose:
// Contains all menu-related functions including displaying the menu, handling choices,...
//
// Version 1 - Trong Tu Le

#include "MenuFunctions.h"
#include "../Helper Functions/HelperFunctions.h"
#include "../Output Functions/OutputFunctions.h"
#include "../Data Collectors/DataCollector.h"

#include <iostream>
#include <iomanip>

//---------------------------------------------------------------------------------

// Displays the menu and processes user choices.
void menu(const WeatherLog& weather_data) {
    bool exit = false;

    while (!exit) {
        showMenu();
        int choice = readChoice();
        exit = processChoice(weather_data, choice);
    }
}

//---------------------------------------------------------------------------------

// Displays the menu options.
void showMenu() {
    std::cout << "Menu: Type(\n"
              << "1 : Display Average Wind Speed And Sample Standard Deviation In A Month Of A Year.\n"
              << "2 : Display Average Ambient Air Temperature And Sample Standard Deviation For Each Month Of A Year.\n"
              << "3 : Display The Correlation Coefficients of Wind Speed, Air Temperature, and Solar Radiation In A Specified Month.\n"
              << "4 : Display Average Wind Speed, Average Ambient Air Temperature, And Total Solar Radiation For Each Month Of A Year.\n"
              << "5 : Exit the program.)\n"
              << "-------------------------------------------------------------------------------------------------------------------"
              << std::endl;
}

//---------------------------------------------------------------------------------

// Function to process user's menu choice and call the appropriate handler.
bool processChoice(const WeatherLog& weather_data, int choice) {
    switch (choice) {
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
            std::cout << "Exiting the program..." << std::endl;
            return true;
        default:
            std::cout << "Invalid choice. Please enter a choice from 1 to 5!\n"
                      << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            return false;
    }
}

//---------------------------------------------------------------------------------

// Handles the first case: processes wind speed data for a specific month and year.
void firstCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();
    int month = readMonth();

    Vector<double> windSpeeds;

    if (weather_data.contains(year) && weather_data.at(year).contains(month)) {
        weather_data.at(year).at(month).inOrder(DataCollector::accumulateData);
        accumulateSpeed(windSpeeds, DataCollector::getData());
    }

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    firstCaseOutput(windSpeeds, month, year);
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    DataCollector::clear();
}

void accumulateSpeed(Vector<double>& windSpeeds, const Vector<WeatherRecord>& data){
    for(LongInt i = 0; i < data.Size(); i++){
        windSpeeds.add(data[i].speed*SpeedExchangeRate);
    }
}

//---------------------------------------------------------------------------------

// Outputs the wind speed data for a specific month and year.
void firstCaseOutput(const Vector<double>& windSpeeds, int month, int year) {
    if (windSpeeds.Size() == 0) {
        outputWindSpeed(0, 0, month, year);
    } else {
        double average = calculateAverage(windSpeeds);
        double stdev = calculateStandardDeviation(windSpeeds);
        outputWindSpeed(average, stdev, month, year);
    }
}

//---------------------------------------------------------------------------------

// Handles the second case: processes temperature data for a specific year.
void secondCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << year << ":" << std::endl;
    if (weather_data.contains(year)) {
        Vector<double> temperatures;

        for (int month = 1; month <= MonthCounts; month++) {
            if (weather_data.at(year).contains(month)) {
                weather_data.at(year).at(month).inOrder(DataCollector::accumulateData);
                accumulateAirTemp(temperatures, DataCollector::getData());
            }
            secondCaseOutput(temperatures, month);

            DataCollector::clear();
            temperatures.Clear();
        }
    } else {
        std::cout << "No data" << std::endl;
    }
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    DataCollector::clear();
}

void accumulateAirTemp(Vector<double>& temperatures, const Vector<WeatherRecord>& data){
    for(LongInt i = 0; i < data.Size(); i++){
        temperatures.add(data[i].airTemp);
    }
}

//---------------------------------------------------------------------------------

// Outputs the temperature data for a specific month and year.
void secondCaseOutput(const Vector<double>& temperatures, int month) {
    if (temperatures.Size() == 0) {
        outputAirTemp(0, 0, month);
    } else {
        double average = calculateAverage(temperatures);
        double stdev = calculateStandardDeviation(temperatures);
        outputAirTemp(average, stdev, month);
    }
}

//---------------------------------------------------------------------------------

// Handles the third case: processes and outputs correlation coefficients.
void thirdCaseHandler(const WeatherLog& weather_data) {
    int month = readMonth();

    Vector<double> windSpeeds, temperatures, solarRads;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    for (WeatherLog::const_iterator it = weather_data.begin(); it != weather_data.end(); ++it) {
        if (it->second.contains(month)) {
            it->second.at(month).inOrder(DataCollector::accumulateData);

            accumulateSpeed(windSpeeds, DataCollector::getData());
            accumulateAirTemp(temperatures, DataCollector::getData());
            accumulateSolarRad(solarRads, DataCollector::getData());
        }

        DataCollector::clear();
    }

    double S_T = calculateCorrelationCoef(windSpeeds, temperatures);
    double S_R = calculateCorrelationCoef(windSpeeds, solarRads);
    double T_R = calculateCorrelationCoef(temperatures, solarRads);

    outputCorrelationCoef(S_T, S_R, T_R, month);
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    DataCollector::clear();
}

void accumulateSolarRad(Vector<double>& solarRads, const Vector<WeatherRecord>& data){
    for(LongInt i = 0; i < data.Size(); i++){
        solarRads.add(data[i].solarRad*RadiationExchangeRate);
    }
}

//---------------------------------------------------------------------------------

// Handles the fourth case: processes and outputs multiple types of weather data for a specific year.
void fourthCaseHandler(const WeatherLog& weather_data) {
    int year = readYear();

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::ofstream outFile("WindTempSolar.csv");
    if (!outFile) {
        std::cout << "Error creating file: WindTempSolar.csv" << std::endl;
        std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
        return;
    }
    outFile << year << std::endl;

    if (weather_data.contains(year)) {
        Vector<double> windSpeeds, temperatures, solarRads;
        for (int month = 1; month <= MonthCounts; month++) {
            if (weather_data.at(year).contains(month)) {
                weather_data.at(year).at(month).inOrder(DataCollector::accumulateData);

                accumulateSpeed(windSpeeds, DataCollector::getData());
                accumulateAirTemp(temperatures, DataCollector::getData());
                accumulateSolarRad(solarRads, DataCollector::getData());
            }
            fourthCaseOutput(outFile, windSpeeds, temperatures, solarRads, month);

            DataCollector::clear();
            windSpeeds.Clear();
            temperatures.Clear();
            solarRads.Clear();
        }
    } else {
        outFile << "No data" << std::endl;
    }

    std::cout << "Write Data to WindTempSolar.csv Successfully" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    outFile.close();

    DataCollector::clear();
}

//---------------------------------------------------------------------------------

// Outputs the weather data to a file for a specific month.
void fourthCaseOutput(std::ofstream& outFile, const Vector<double>& windSpeeds, const Vector<double>& temperatures, const Vector<double>& solarRadiations, int month) {
    if (!(windSpeeds.Size() == 0 && temperatures.Size() == 0 && solarRadiations.Size() == 0)) {
        outFile << MonthsNames[month - 1] << "," << std::fixed << std::setprecision(1);

        outputToFileAvgSdMAD(outFile, windSpeeds);
        outputToFileAvgSdMAD(outFile, temperatures);

        if (solarRadiations.Size() != 0) {
            double totalRadiation = calculateTotal(solarRadiations);
            outFile << totalRadiation << std::endl;
        } else {
            outFile << "," << std::endl;
        }
    }
}

//---------------------------------------------------------------------------------

// Outputs the average, standard deviation, and mean absolute deviation of a vector to a file.
void outputToFileAvgSdMAD(std::ofstream& outFile, const Vector<double>& array){
    if (array.Size() != 0) {
        double avg = calculateAverage(array);
        double stdev = calculateStandardDeviation(array);
        double mad = calculateMAD(array);
        outFile << "\"" << avg << "(" << stdev << ", " << mad << ")\",";
    } else {
        outFile << ",";
    }
}

//---------------------------------------------------------------------------------
