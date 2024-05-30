#ifndef OPERATOR_H
#define OPERATOR_H

#include "../Data Structures/DataStructure.h"

/**
 * @brief Less than operator for Date.
 *
 * Compares two Date objects.
 *
 * @param lhs Left-hand side Date.
 * @param rhs Right-hand side Date.
 * @return true if lhs is less than rhs.
 * @return false otherwise.
 */
bool operator<(const Date& lhs, const Date& rhs);

/**
 * @brief Greater than operator for Date.
 *
 * Compares two Date objects.
 *
 * @param lhs Left-hand side Date.
 * @param rhs Right-hand side Date.
 * @return true if lhs is greater than rhs.
 * @return false otherwise.
 */
bool operator>(const Date& lhs, const Date& rhs);

/**
 * @brief Equality operator for Date.
 *
 * Compares two Date objects.
 *
 * @param lhs Left-hand side Date.
 * @param rhs Right-hand side Date.
 * @return true if lhs is equal to rhs.
 * @return false otherwise.
 */
bool operator==(const Date& lhs, const Date& rhs);

bool operator<(const Time& lhs, const Time& rhs);

bool operator>(const Time& lhs, const Time& rhs);

/**
 * @brief Equality operator for Time.
 *
 * Compares two Time objects.
 *
 * @param lhs Left-hand side Time.
 * @param rhs Right-hand side Time.
 * @return true if lhs is equal to rhs.
 * @return false otherwise.
 */
bool operator==(const Time& lhs, const Time& rhs);

/**
 * @brief Less than operator for WeatherRecord.
 *
 * Compares two WeatherRecord objects.
 *
 * @param lhs Left-hand side WeatherRecord.
 * @param rhs Right-hand side WeatherRecord.
 * @return true if lhs is less than rhs.
 * @return false otherwise.
 */
bool operator<(const WeatherRecord& lhs, const WeatherRecord& rhs);

/**
 * @brief Greater than operator for WeatherRecord.
 *
 * Compares two WeatherRecord objects.
 *
 * @param lhs Left-hand side WeatherRecord.
 * @param rhs Right-hand side WeatherRecord.
 * @return true if lhs is greater than rhs.
 * @return false otherwise.
 */
bool operator>(const WeatherRecord& lhs, const WeatherRecord& rhs);

/**
 * @brief Equality operator for WeatherRecord.
 *
 * Compares two WeatherRecord objects.
 *
 * @param lhs Left-hand side WeatherRecord.
 * @param rhs Right-hand side WeatherRecord.
 * @return true if lhs is equal to rhs.
 * @return false otherwise.
 */
bool operator==(const WeatherRecord& lhs, const WeatherRecord& rhs);

#endif
