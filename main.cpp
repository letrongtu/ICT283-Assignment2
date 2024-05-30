// MAIN.CPP
// Main program:
// Open an input file stream, read recorded data, display the menu, and handle the menu options.
#include "DataStructure.h"
#include "FileNameReader.h"
#include "MenuFunctions.h"
#include <iostream>

/**
 * @author Trong Tu Le
 * @version 1
 * Read the data from a csv file, store all required data into a WindRecType type Vector. Calculate average speed, standard deviation,
 * and find the data that match with the average speed
 * @version 2
 * Separate additional function declarations and implementations
 */

int main()
{
//-----------------------------------------------------
// Read and Store data
    WeatherLog weather_data;
    readFileFromSource("data/data_source.txt", weather_data);
//-----------------------------------------------------
// Menu
    menu(weather_data);
//-----------------------------------------------------
    std::cout << "Quit" << std::endl;
    return 0;
}
