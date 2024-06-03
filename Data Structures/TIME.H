#ifndef TIME_H
#define TIME_H
//---------------------------------------------------------------------------------

/**
 * @class Time
 * @brief Represents a time with hour and minute
 *
 * Provides functionality to manipulate and format time.
 *
 * @author Trong Tu Le
 * @version 1
 */

//---------------------------------------------------------------------------------

class Time {
public:
    /**
     * @brief Default constructor. Initializes hour and minute to 0.
     */
    Time();

    /**
     * @brief Parameterized constructor. Initializes hour and minutewith given values.
     *
     * @param d Day
     * @param m Month
     * @param y Year
     */
    Time(int h, int m);

    /**
     * @brief Get the hour.
     *
     * @return int hour
     */
    int GetHour() const;

    /**
     * @brief Set the hour.
     *
     * @param h - hour
     * @return void
     */
    void SetHour(int h);

    /**
     * @brief Get the minute.
     *
     * @return int minute
     */
    int GetMinute() const;

    /**
     * @brief Set the minute.
     *
     * @param m - minute
     * @return void
     */
    void SetMinute(int m);

private:
    int hour; /// Date
    int minute; /// Month
};

//---------------------------------------------------------------------------------

#endif
