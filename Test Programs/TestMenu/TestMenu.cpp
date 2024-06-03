#include "../../Menu Functions/MenuFunctions.h"
#include "../../Menu Functions/MenuFunctions.cpp"
#include "../../Helper Functions/HelperFunctions.h"
#include "../../Helper Functions/HelperFunctions.cpp"
#include "../../Helper Functions/Validator.h"
#include "../../Helper Functions/Validator.cpp"
#include "../../Output Functions/OutputFunctions.h"
#include "../../Output Functions/OutputFunctions.cpp"
#include "../../Data Collectors/DataCollector.h"
#include "../../Data Collectors/DataCollector.cpp"
#include "../../Data Structures/DataStructure.h"
#include "../../Data Structures/WeatherRecord.h"
#include "../../Data Structures/WeatherRecord.cpp"
#include "../../Data Structures/Date.h"
#include "../../Data Structures/Date.cpp"
#include "../../Data Structures/Time.h"
#include "../../Data Structures/Time.cpp"
#include "../../Operator/operator.h"
#include "../../Operator/operator.cpp"

#include <iostream>

// Mock data to simulate weather data
void loadData(WeatherLog& weather_data) {
    // Example data for testing
    WeatherRecord record1(Date(2023, 1, 10), Time(12, 0), 10.0, 300.0, 5.0);
    WeatherRecord record2(Date(2023, 1, 15), Time(14, 0), 12.0, 350.0, 7.0);
    WeatherRecord record3(Date(2023, 2, 5), Time(10, 0), 9.0, 320.0, 6.0);
    WeatherRecord record4(Date(2023, 2, 20), Time(16, 0), 11.0, 330.0, 8.0);

    weather_data[2023][1].insert(record1);
    weather_data[2023][1].insert(record2);
    weather_data[2023][2].insert(record3);
    weather_data[2023][2].insert(record4);
}

// Test functions for each menu option
void testFirstCaseHandler() {
    WeatherLog weather_data;
    loadData(weather_data);

    std::cout << "Testing First Case Handler (Enter 2023, Then 1 or 2 for valid data)\n";
    firstCaseHandler(weather_data);
}

void testSecondCaseHandler() {
    WeatherLog weather_data;
    loadData(weather_data);

    std::cout << "Testing Second Case Handler (Enter 2023 for valid data)\n";
    secondCaseHandler(weather_data);
}

void testThirdCaseHandler() {
    WeatherLog weather_data;
    loadData(weather_data);

    std::cout << "Testing Third Case Handler (Enter 1 or 2 for valid data)\n";
    thirdCaseHandler(weather_data);
}

void testFourthCaseHandler() {
    WeatherLog weather_data;
    loadData(weather_data);

    std::cout << "Testing Fourth Case Handler\n";
    fourthCaseHandler(weather_data);
}

void testMenu() {
    WeatherLog weather_data;
    loadData(weather_data);

    std::cout << "Testing Menu Function\n";

    menu(weather_data);
}

int main() {
    testFirstCaseHandler();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    testSecondCaseHandler();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    testThirdCaseHandler();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    testFourthCaseHandler();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    testMenu();

    return 0;
}
