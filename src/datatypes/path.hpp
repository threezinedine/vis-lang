#pragma once
#include "object.hpp"
#include "string.hpp"
#include "memory.hpp"

#if MINGW
#include <filesystem>
namespace fs = std::filesystem;
#elif MSVC
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif


namespace ntt
{
    /**
     * The class which is used for working with applicaiton paths of files
     *      and directories. This method will be used for all the paths inside
     *      this project.
     */
    class Path : public Object
    {
    public:
        Path(const char *path);
        Path(const std::string &path);
        Path(const String &path);
        Path(const Path &path);

        virtual ~Path();

        virtual String ToString() const override;

        /**
         * Check whether the current value exists in the file system or not.
         *      This method should be called before some checking methods of the
         *      current value for avoiding the error while using.
         *
         * @return
         * @retval True if the current path exists in the file system.
         * @retval False if the current path does not exist in the file system.
         */
        B8 Exists() const;

        /**
         * Check whether the current value is a folder or a file.
         *      should be used before getting the file name or directory name
         *      of the current path.
         *
         * @return True if the current path is a directory, False otherwise.
         *
         * @note Should be used after check the `Exists` method or the error will
         *      be thrown.
         *
         * @example
         * ```cpp
         * Path path("C:/Users/username/Documents");
         * if (path.Exists())
         * {
         *      if (path.IsDirectory())
         *      {
         *          // Do something with the directory
         *      }
         * }
         * ```
         */
        B8 IsDirectory() const;

        /**
         * Extract the file name of the current path. If the path is a directory then
         *      the error will be thrown, so that should check the path is directory
         *      or file before calling this method.
         *
         * @param containExtension Whether to include the extension of the file or not.
         *      If this is set to False, the extension will be removed from the file name.
         *      Default value is True.
         *
         * @return The file name of the current path.
         *
         * @note Should be used after check the `Exists` and `IsDirectory` method.
         *
         * @example
         * ```cpp
         * Path path("C:/Users/username/Documents/test.txt");
         *
         * if (!path.Exists())
         * {
         *      // Do something with the error
         *      return;
         * }
         *
         * if (path.IsDirectory())
         * {
         *      // Do something with the directory
         * }
         *
         * String fileName = path.GetFileName(); ///< "test.txt"
         * String fileNameWithoutExtension = path.GetFileName(False); ///< "test"
         * ```
         */
        String GetFileName(B8 containExtension = True) const;

    private:
        fs::path m_path;
    };
} // namespace ntt
