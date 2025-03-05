#pragma once
#include "object.hpp"
#include "string.hpp"
#include "memory.hpp"
#include "array.hpp"
#include "dictionary.hpp"

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
     *
     * The file manipulation operations will be done by this class. These operations
     *      can be done also in different threads without any confliction.
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

        /**
         * The first operation which must be called before every file manipulation
         *      operation. This method will open the file in the file system.
         *
         * If the path is already opened, this method will do nothing, other operations
         *      still can be called, no confliction will be happened.
         *
         * If the path is a directory, nothing will be happened, other operations will be
         *      ignored.
         *
         * @param createIfNotExist Whether to create the file if it does not exist or not.
         *      If this is set to True, the file will be created if it does not exist.
         */
        void Open(B8 createIfNotExist = False);

        /**
         * Verify whether the current path is opened or not, this is just for the current
         *      path object, other objects with the same path can be different.
         *
         * @param return True if the current path is opened, False otherwise.
         */
        inline B8 IsOpened() const { return m_isPathOpened; }

        /**
         * Obtain the content of the file and return it as a string object.
         * The file must be opened before calling this method or the error will be thrown.
         *
         * @return The content of the file as a string object.
         */
        String Read() const;

        /**
         * Append the new string to the end of the file or write it to the beginning of the file.
         * The file must be opened before calling this method or the error will be thrown.
         *
         * @param content The content to be written to the file.
         * @param append If this is set to True, the content will
         *          be appended to the end of the file. If this is
         *          set to False, the content will be written to the
         *          beginning of the file.
         */
        void Write(const String &content, B8 append = True);

        /**
         * Obtain the content of the file and return it as an array of bytes.
         * The file must be opened before calling this method or the error will be thrown.
         *
         * @return The content of the file as an array of bytes.
         */
        Array<U8> ReadBytes() const;

        /**
         * Append the new bytes to the end of the file or write it to the beginning of the file.
         * The file must be opened before calling this method or the error will be thrown.
         *
         * @param content The content to be written to the file.
         * @param append If this is set to True, the content will
         *      be appended to the end of the file. If this is
         *      set to False, the content will be written to the
         *      beginning of the file.
         */
        void WriteBytes(const Array<U8> &content, B8 append = True);

        /**
         * Used for freeing the needed resources for the current path object. Other object
         *      with the same path is not affected by this operation.
         *
         * If the path is not opened, this method will do nothing.
         */
        void Close();

    private:
        fs::path m_path;
        B8 m_isPathOpened;

    private:
        /**
         * Used each time the path is modified, this method will automatically
         *      beautify the path for the current path object (based on the OS).
         */
        void BeautifyPath();
    };
} // namespace ntt
