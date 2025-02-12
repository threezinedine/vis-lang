#pragma once
#include "object.hpp"
#include "string.hpp"

namespace ntt
{
    /**
     * The class which is used for working with applicaiton paths of files
     *      and directories. This method will be used for all the paths inside
     *      this project.
     */
    class Path : public Object, public String
    {
    public:
        /**
         * Current folder which consists of the code which calls this constructor
         *      will be assigned to the path.
         */
        Path();

        Path(const char *path);
        Path(const std::string &path);
        Path(const String &path);
        Path(const Path &path);

        virtual ~Path();

        virtual String ToString() const override;

        /**
         * Extract the file name of the current path.B8
         *
         * @param containExtension Whether to include the extension of the file or not.
         *      If this is set to False, the extension will be removed from the file name.
         *      Default value is True.
         *
         * @return The file name of the current path.
         *
         * @example
         * ```cpp
         * Path path("C:/Users/username/Documents/test.txt");
         * String fileName = path.GetFileName(); // test.txt
         * String fileNameWithoutExtension = path.GetFileName(False); // test
         * ```
         */
        String GetFileName(B8 containExtension = True) const;
    };
} // namespace ntt
