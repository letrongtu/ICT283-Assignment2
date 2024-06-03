#include <iostream>
#include "../../Data Structures/Vector.h"
#include "../../Helper Functions/HelperFunctions.h"
#include "../../Helper Functions/HelperFunctions.cpp"
#include "../../Helper Functions/Validator.h"
#include "../../Helper Functions/Validator.cpp"

void TestCalculateAverage() {
    Vector<double> array;
    array.add(1.0);
    array.add(2.0);
    array.add(3.0);
    array.add(4.0);
    array.add(5.0);
    std::cout << "Testing calculateAverage function:" << std::endl;
    std::cout << "Expected: 3.0, Actual: " << calculateAverage(array) << std::endl;
}

void TestCalculateStandardDeviation() {
    Vector<double> array;
    array.add(1.0);
    array.add(2.0);
    array.add(3.0);
    array.add(4.0);
    array.add(5.0);
    std::cout << "Testing calculateStandardDeviation function:" << std::endl;
    std::cout << "Expected: 1.41421, Actual: " << calculateStandardDeviation(array) << std::endl;  // Approximation
}

void TestCalculateSumSquared() {
    Vector<double> array;
    array.add(1.0);
    array.add(2.0);
    array.add(3.0);
    array.add(4.0);
    array.add(5.0);
    double mean = calculateAverage(array);
    std::cout << "Testing calculateSumSquared function:" << std::endl;
    std::cout << "Expected: 10.0, Actual: " << calculateSumSquared(array, mean) << std::endl;
}

void TestCalculateTotal() {
    Vector<double> array;
    array.add(1.0);
    array.add(2.0);
    array.add(3.0);
    array.add(4.0);
    array.add(5.0);
    std::cout << "Testing calculateTotal function:" << std::endl;
    std::cout << "Expected: 15.0, Actual: " << calculateTotal(array) << std::endl;
}

void TestCalculateCorrelationCoef() {
    Vector<double> array1;
    array1.add(1.0);
    array1.add(2.0);
    array1.add(3.0);
    array1.add(4.0);
    array1.add(5.0);
    Vector<double> array2;
    array2.add(2.0);
    array2.add(4.0);
    array2.add(6.0);
    array2.add(8.0);
    array2.add(10.0);
    std::cout << "Testing calculateCorrelationCoef function:" << std::endl;
    std::cout << "Expected: 1.0, Actual: " << calculateCorrelationCoef(array1, array2) << std::endl;  // Perfect positive correlation
}

void TestCalculateMAD() {
    Vector<double> array;
    array.add(1.0);
    array.add(2.0);
    array.add(3.0);
    array.add(4.0);
    array.add(5.0);
    std::cout << "Testing calculateMAD function:" << std::endl;
    std::cout << "Expected: 1.2, Actual: " << calculateMAD(array) << std::endl;
}

int main() {
    TestCalculateAverage();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestCalculateStandardDeviation();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestCalculateSumSquared();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestCalculateTotal();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestCalculateCorrelationCoef();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    TestCalculateMAD();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "All tests completed" << std::endl;
    return 0;
}
