#include "path.hpp"
#include <utilities/utilities.hpp>

namespace ntt
{
    Path::Path(const char *path)
        : Object(), m_path(fs::path(path))
    {
    }

    Path::Path(const std::string &path)
        : Object(), m_path(fs::path(path))
    {
    }

    Path::Path(const String &path)
        : Object(),
          m_path(fs::path(path.c_str()))
    {
    }

    Path::Path(const Path &path)
        : Object(),
          m_path(path.m_path)
    {
    }

    Path::~Path()
    {
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
}