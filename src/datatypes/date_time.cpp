#include "date_time.hpp"
#include <utilities/format_string.hpp>

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
            .Replace("%m", ConvertToString(m_month), True)
            .Replace("%d", ConvertToString(m_day), True)
            .Replace("%H", ConvertToString(m_hour), True)
            .Replace("%M", ConvertToString(m_minute), True)
            .Replace("%S", ConvertToString(m_second), True)
            .Replace("%C", ConvertMonthToText(m_month), True);
    }

    String DateTime::ToString() const
    {
        return Format("<DateTime {}-{}-{} {}:{}:{} />",
                      m_year, m_month, m_day,
                      m_hour, m_minute, m_second);
    }
} // namespace ntt
