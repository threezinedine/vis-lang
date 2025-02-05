#pragma once
#include "object.hpp"

namespace ntt
{
    /**
     * Store the calendar date information and support some
     *      needed operations for the date. The object contains
     *      both date and time information.
     *
     * @example
     * ```cpp
     * DateTime dt; // default unix epoch time: 1970-01-01 00:00:00
     * DateTime dt = DateTime::Now(); // current date and time
     *
     * DateTime date(2020, 3, 18); // time defaults to 00:00:00
     * DateTime date(2020, 3, 32); // invalid date will throw an exception
     * ```
     */
    class DateTime : public Object
    {
    public:
        /**
         * Initialization of the date object with the given date and time.
         * If the date is invalid, the object will throw an exception.
         *
         * @param year The year of the date.
         * @param month The month of the date.
         * @param day The day of the date.
         * @param hour The hour of the date.
         * @param minute The minute of the date.
         * @param second The second of the date.
         */
        DateTime(U16 year = 1970, U8 month = 1, U8 day = 1,
                 U8 hour = 0, U8 minute = 0, U8 second = 0);

        /**
         * Get the datetime information string in a user-defined way. The
         *      format string can contain the following placeholders:
         *      - %Y: Year with century as a decimal number (format YYYY)
         *      - %m: Month as a decimal number [01,12] (format mm)
         *      - %d: Day of the month as a decimal number [01,31] (format dd)
         *
         *      - %H: Hour (24-hour clock) as a decimal number [00,23] (format HH)
         *      - %M: Minute as a decimal number [00,60] (format MM)
         *      - %S: Second as a decimal number [00,60] (format SS)
         *
         *      - %C: Month as locale’s abbreviated name (e.g., Jan, Feb, Mar).
         *
         * @param format The format string which will be used to format the date.
         *      The format string can contain the placeholders. If the format string
         *      is empty, the default format will be used ("%Y-%m-%d %H:%M:%S").
         *
         * @return The formatted date string.
         *
         * @example
         * ```cpp
         * DateTime dt(2021, 10, 10, 10, 10, 10);
         * dt.Format("Time: %H:%M:%S, Date: %Y-%m-%d"); // Time: 10:10:10, Date: 2021-10-10
         * ```
         */
        String WithFormat(const String &format) const;

        /**
         * Retrieve the current date and time information with the UTC timezone
         *      or the local timezone of the system.
         *
         * @param uct If the value is True, the function will return the current
         *      date and time information with the UTC timezone. Otherwise, the
         *      function will return the current date and time information with
         *      the local timezone of the system.
         *
         * @return The current date and time information.
         */
        static DateTime Now(B8 uct = False);

        String ToString() const override;

        inline U16 GetYear() const { return m_year; }
        inline U8 GetMonth() const { return m_month; }
        inline U8 GetDay() const { return m_day; }
        inline U8 GetHour() const { return m_hour; }
        inline U8 GetMinute() const { return m_minute; }
        inline U8 GetSecond() const { return m_second; }

    private:
        U16 m_year;
        U8 m_month;
        U8 m_day;
        U8 m_hour;
        U8 m_minute;
        U8 m_second;
    };
} // namespace ntt
