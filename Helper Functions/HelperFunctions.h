#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include "../Data Structures/DataStructure.h"
#include "../Data Structures/vector.h"

//---------------------------------------------------------------------------------

/**
 * @brief Contains all functions that calculate the required metrics related to weather data.
 *
 * This header defines various helper functions needed to perform calculations
 * related to weather data, such as reading user input, calculating statistical
 * measures, and more.
 *
 * @version 01
 * @author Trong Tu Le
 * @file HelperFunctions.h
 */

//---------------------------------------------------------------------------------

/**
 * @brief Reads and returns the user's choice from the menu.
 *
 * @return The user's menu choice as an integer.
 */
int readChoice();

/**
 * @brief Reads and returns the user's input for the year.
 *
 * @return The year entered by the user as an integer.
 */
int readYear();

/**
 * @brief Reads and returns the user's input for the month.
 *
 * @return The month entered by the user as an integer.
 */
int readMonth();

/**
 * @brief Calculates and returns the average of the values in the array.
 *
 * @param array A vector of double values.
 * @return The average of the values in the array.
 */
double calculateAverage(const Vector<double>& array);

/**
 * @brief Calculates and returns the standard deviation of the values in the array.
 *
 * @param array A vector of double values.
 * @return The standard deviation of the values in the array.
 */
double calculateStandardDeviation(const Vector<double>& array);

/**
 * @brief Calculates and returns the sum of squared differences from the mean.
 *
 * @param array A vector of double values.
 * @param mean The mean of the values in the array.
 * @return The sum of squared differences from the mean.
 */
double calculateSumSquared(const Vector<double>& array, double mean);

/**
 * @brief Calculates and returns the total sum of the values in the array.
 *
 * @param array A vector of double values.
 * @return The total sum of the values in the array.
 */
double calculateTotal(const Vector<double>& array);

/**
 * @brief Calculates and returns the correlation coefficient between two arrays.
 *
 * @param array1 A vector of double values representing the first dataset.
 * @param array2 A vector of double values representing the second dataset.
 * @return The correlation coefficient between the two arrays.
 */
double calculateCorrelationCoef(const Vector<double>& array1, const Vector<double>& array2);

/**
 * @brief Calculates and returns the Mean Absolute Deviation (MAD) of the values in the array.
 *
 * @param array A vector of double values.
 * @return The Mean Absolute Deviation of the values in the array.
 */
double calculateMAD(const Vector<double>& array);

//---------------------------------------------------------------------------------

#endif
