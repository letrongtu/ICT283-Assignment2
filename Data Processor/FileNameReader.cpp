// FileNameReader.cpp
// Purpose:
// Contains all functions need to read the input file name
//
// Version 1 - Trong Tu Le

#include "FileNameReader.h"
#include "DataProcessor.h"
#include <iostream>
#include <fstream>
#include <string>

//---------------------------------------------------------------------------------

// Reads weather data from a file and stores it in the WeatherLog structure.
void readFileFromSource(const std::string& sourceFile, WeatherLog& weather_data){
    std::ifstream sourceInput(sourceFile);
    if (!sourceInput) {
        std::cout << "Error opening file: " << sourceFile << std::endl;
        return;
    }

    std::string fileName;
    while (std::getline(sourceInput, fileName)) {
        readData(fileName, weather_data);
    }

    sourceInput.close();
}

//---------------------------------------------------------------------------------
