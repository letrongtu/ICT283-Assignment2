#include <iostream>
#include "../../Helper Functions/Validator.h"
#include "../../Helper Functions/Validator.cpp"

void TestIsValidNumberFunction() {
    std::cout << "Testing isValidNumber function:" << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidNumber("123") << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidNumber("123.45") << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidNumber("-123") << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidNumber("abc") << std::endl;
}

void TestIsValidDateFunction() {
    std::cout << "Testing isValidDate function:" << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidDate(29, 2, 2020) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidDate(29, 2, 2019) << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidDate(31, 12, 2020) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidDate(32, 1, 2020) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidDate(0, 1, 2020) << std::endl;
}

void TestIsValidYearFunction() {
    std::cout << "Testing isValidYear function:" << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidYear(2020) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidYear(0) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidYear(10000) << std::endl;
}

void TestIsValidMonthFunction() {
    std::cout << "Testing isValidMonth function:" << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidMonth(1) << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidMonth(12) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidMonth(0) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidMonth(13) << std::endl;
}

void TestIsValidTimeFunction() {
    std::cout << "Testing isValidTime function:" << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidTime(0, 0) << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidTime(23, 59) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidTime(24, 0) << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidTime(0, 60) << std::endl;
}

int main() {
    TestIsValidNumberFunction();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestIsValidDateFunction();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestIsValidYearFunction();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestIsValidMonthFunction();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestIsValidTimeFunction();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "All tests completed" << std::endl;
    return 0;
}
