#include "path.hpp"
#include <utilities/utilities.hpp>
#include <fstream>
#include "dictionary.hpp"
#include "memory.hpp"

namespace ntt
{
    namespace
    {
        /**
         * Interla data structure for storing global file handler hub.
         */
        struct FileHandlingData : public Object
        {
            Ref<std::fstream> pStream; ///< The pointer to the file stream (cannot use Scope)
            U16 openCount;             ///< The number of opening the file.

            FileHandlingData() : pStream(nullptr), openCount(0) {}

            virtual String ToString() const override
            {
                return Format("<FileHandlingData count={} />", openCount);
            }
        };

        /**
         * The singleton center map which stores all opening file handlers in
         *      the system. This map will be used for avoiding the confliction
         *      between the file handlers (in main thread and other threads).
         */
        Dictionary<String, FileHandlingData> s_openedFiles;
    } // namespace anonymous

    Path::Path(const char *path)
        : Object(), m_path(fs::path(path)), m_isPathOpened(False)
    {
        BeautifyPath();
    }

    Path::Path(const std::string &path)
        : Object(), m_path(fs::path(path)), m_isPathOpened(False)
    {
        BeautifyPath();
    }

    Path::Path(const String &path)
        : Object(),
          m_path(fs::path(path.c_str())),
          m_isPathOpened(False)
    {
        BeautifyPath();
    }

    Path::Path(const Path &path)
        : Object(),
          m_path(path.m_path)
    {
        BeautifyPath();
    }

    Path::~Path()
    {
        if (IsOpened())
        {
            Close();
        }
    }

    B8 Path::Exists() const
    {
        return fs::exists(m_path);
    }

    B8 Path::IsDirectory() const
    {
        if (!Exists())
        {
            throw std::runtime_error(
                "The current path does not exist in the file system.");
        }

        return fs::is_directory(m_path);
    }

    String Path::GetFileName(B8 containExtension) const
    {
        if (IsDirectory())
        {
            throw std::runtime_error(
                "The current path is a directory, so cannot get the file name.");
        }

        if (!containExtension)
        {
            return String(m_path.stem().string());
        }
        else
        {
            return String(m_path.filename().string());
        }
    }

    String Path::ToString() const
    {
        return Format("<Path: {}>", String(m_path.string()));
    }

    void Path::Open(B8 createIfNotExist)
    {
        if (!Exists())
        {
            if (!createIfNotExist)
            {
                throw std::runtime_error(
                    "The current path does not exist in the file system.");
            }
            else
            {
                std::fstream file(m_path.c_str(), std::ios::out);
                file.close();
            }
        }

        if (IsDirectory())
        {
            throw std::runtime_error(
                "The current path is a directory, so cannot open the file.");
        }

        if (s_openedFiles.Contains(m_path.string()) == False)
        {
            s_openedFiles[m_path.string()] = {};
            s_openedFiles[m_path.string()].pStream = CreateRef<std::fstream>(
                m_path.c_str(), std::ios::in | std::ios::out | std::ios::binary);
            s_openedFiles[m_path.string()].openCount = 1;
        }
        else
        {
            s_openedFiles[m_path.string()].openCount++;
        }

        m_isPathOpened = True;
    }

    String Path::Read() const
    {
        if (!IsOpened())
        {
            throw std::runtime_error(
                "The current path is not opened, so cannot read the file.");
        }

        if (IsDirectory())
        {
            throw std::runtime_error(
                "The current path is a directory, so cannot read the file.");
        }

        if (!s_openedFiles.Contains(m_path.string()))
        {
            throw std::runtime_error(
                "The current path is not opened, so cannot read the file.");
        }

        Ref<std::fstream> &fileHandler = s_openedFiles[m_path.string()].pStream;

        fileHandler->seekg(0, std::ios::end);
        U64 size = fileHandler->tellg();
        fileHandler->seekg(0, std::ios::beg);

        std::string content(size, '\0');
        fileHandler->read(&content[0], size);

        return String(content);
    }

    void Path::Write(const String &content, B8 append)
    {
        Ref<std::fstream> &fileHandler = s_openedFiles[m_path.string()].pStream;

        if (append)
        {
            fileHandler->seekp(0, std::ios::end);
        }
        else
        {
            fileHandler->seekp(0, std::ios::beg);
        }

        fileHandler->write(content.c_str(), content.size());
        fileHandler->flush();
    }

    void Path::Close()
    {
        if (s_openedFiles.Contains(m_path.string()) == False)
        {
            return;
        }

        s_openedFiles[m_path.string()].openCount--;
        if (s_openedFiles[m_path.string()].openCount == 0)
        {
            s_openedFiles[m_path.string()].pStream->close();
            s_openedFiles.Remove(m_path.string());
        }
    }

    void Path::BeautifyPath()
    {
        m_path = fs::absolute(m_path);
    }
}