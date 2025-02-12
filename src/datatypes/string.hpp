#pragma once
#include "common.hpp"
#include <string>

namespace ntt
{
    /**
     * Application self-defined string data type. This class will contains multiple supported
     *      string operations that are not available in the standard C++ string class.
     */
    class String : public std::string
    {
    public:
        String();
        String(const char *msg);
        String(const std::string &msg);
        String(const String &other);
        ~String();

        /**
         * Use this method to create a completely new string which some parts of the original
         *      string are replaced with the new string.
         *
         * @note This method will not modify the original string.
         *
         * @param old_str The string to be replaced. If the string is empty, the method will
         *      do nothing and return the original string.
         * @param new_str The string to replace with the old one, there's no restriction on
         *      the length of the string.
         * @param all If this is set to TRUE, all the occurrences of the old string will be
         *      replaced with the new string. Otherwise, only the first occurrence will be
         *      replaced. The default value is FALSE.
         *
         * @return A completely new string instance with the replaced content.
         */
        String Replace(const String &old_str,
                       const String &new_str,
                       B8 all = False) const;

        /**
         * Use this method to extend the current string with a given number of characters.
         * If the number of characters is less than the current setup length, the method
         *      will add the `fill_str` to the start or the end of the string to make the
         *      string have the >= number of characters.
         *
         * @param length The number of characters that the string should at least have.
         * @param fill_str The string to fill the current string with. The length of the
         *      `fill_str` must be not zero else the method will do nothing and return the
         *      original string.
         * @param atStart If this is set to TRUE, the `fill_str` will be added to the start
         *      of the string. Otherwise, it will be added to the end of the string. The
         *      default value is TRUE.
         * @param exact If this is set to TRUE, the `fill_str` will be added to the string
         *      until the string has the exact number of characters, if the final added
         *      makes the string longer than the length, the method will add only a portion
         *      of the `fill_str` at the last step.
         *      If this is set to FALSE, the `fill_str` will be added to the string until the
         *      string has at least the number of characters. The default value is FALSE.
         *
         * @note In the case the length of the string >= length, this method call will be ignored,
         *  the original string will be returned.
         */
        String FillWith(U32 length, const String &fill_str,
                        B8 atStart = True, B8 exact = False) const;

        /**
         * Use to extract a portion of the string from the original string. The method will
         *      return a unique string instance that contains the extracted portion of the
         *      original string.
         *
         * @param start The index of the first character of the extracted string. The index
         *      is 0-based. If the start index is greater than the number of characters in the
         *      original string, the method will return an empty string.
         * @param length The number of characters to extract from the original string. If the
         *      length is greater than the number of characters from the start index to the
         *      end of the string, the method will extract all the characters from the start
         *      index to the end of the string.
         */
        String SubString(U32 start, U32 length) const;

    private:
    };
} // namespace ntt
