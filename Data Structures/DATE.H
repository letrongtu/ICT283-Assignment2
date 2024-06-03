#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------

/**
	 * @class Date
	 * @brief  Represents a date including date, month and year
	 *
	 * @author Trong Tu Le
	 * @version 01
     * @version 02
     *  remove overloaded operators
	 */

//---------------------------------------------------------------------------------

class Date {
public:
    /**
     * @brief Default constructor. Initializes date, month, and year to 0.
     */
    Date();

    /**
     * @brief Parameterized constructor. Initializes date, month, and year with given values.
     *
     * @param d Day
     * @param m Month
     * @param y Year
     */
    Date(int d, int m, int y);

    /**
     * @brief Get the day.
     *
     * @return int Day
     */
    int GetDate() const;

    /**
     * @brief Set the day.
     *
     * @param d - Day
     * @return void
     */
    void SetDate(int d);
    /**
     * @brief Get the month.
     *
     * @return int Month
     */
    int GetMonth() const;

    /**
     * @brief Set the month.
     *
     * @param m - Month
     * @return void
     */
    void SetMonth(int m);

    /**
     * @brief Get the year.
     *
     * @return int Year
     */
    int GetYear() const;

    /**
     * @brief Set the year.
     *
     * @param y - Year
     * @return void
     */
    void SetYear(int y);

private:
    int date; /// Date
    int month; /// Month
    int year; /// Year
};

//---------------------------------------------------------------------------------

#endif
