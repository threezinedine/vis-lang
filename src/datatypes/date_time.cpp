#include "date_time.hpp"
#include <utilities/format_string.hpp>
#include <chrono>

namespace ntt
{
    namespace
    {
        String ConvertMonthToText(U8 month)
        {
            switch (month)
            {
            case 1:
                return "Jan";
            case 2:
                return "Feb";
            case 3:
                return "Mar";
            case 4:
                return "Apr";
            case 5:
                return "May";
            case 6:
                return "Jun";
            case 7:
                return "Jul";
            case 8:
                return "Aug";
            case 9:
                return "Sep";
            case 10:
                return "Oct";
            case 11:
                return "Nov";
            case 12:
                return "Dec";
            default:
                return "Invalid";
            }
        }
    } // namespace anonymous

    DateTime::DateTime(U16 year, U8 month, U8 day, U8 hour, U8 minute, U8 second)
        : m_year(year), m_month(month), m_day(day),
          m_hour(hour), m_minute(minute), m_second(second)
    {
    }

    String DateTime::WithFormat(const String &format) const
    {
        return format.Replace("%Y", ConvertToString(m_year), True)
            .Replace("%m", ConvertToString(m_month).FillWith(2, "0"), True)
            .Replace("%d", ConvertToString(m_day).FillWith(2, "0"), True)
            .Replace("%H", ConvertToString(m_hour).FillWith(2, "0"), True)
            .Replace("%M", ConvertToString(m_minute).FillWith(2, "0"), True)
            .Replace("%S", ConvertToString(m_second).FillWith(2, "0"), True)
            .Replace("%C", ConvertMonthToText(m_month), True);
    }

    String DateTime::ToString() const
    {
        return Format("<DateTime {} />", WithFormat("%Y-%m-%d %H:%M:%S"));
    }

    DateTime DateTime::Now(B8 uct)
    {
        DateTime dt;

        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);

        struct tm *time_info;
        if (uct)
        {
            time_info = std::gmtime(&now_time);
        }
        else
        {
            time_info = std::localtime(&now_time);
        }

        dt.m_year = time_info->tm_year + 1900;
        dt.m_month = time_info->tm_mon + 1;
        dt.m_day = time_info->tm_mday;
        dt.m_hour = time_info->tm_hour;
        dt.m_minute = time_info->tm_min;
        dt.m_second = time_info->tm_sec;

        return dt;
    }
} // namespace ntt
