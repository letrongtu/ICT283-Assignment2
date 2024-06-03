// MAIN.CPP
// Main program:
// Open an input file stream, read recorded data, display the menu, and handle the menu options.
#include "./Data Structures/DataStructure.h"
#include "./Data Processor/FileNameReader.h"
#include "./Menu Functions/MenuFunctions.h"
#include <iostream>

/**
 * @author Trong Tu Le
 * @version 1
 * @version 2
 * Separate additional function declarations and implementations
 */
//---------------------------------------------------------------------------------

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
