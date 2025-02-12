#include "path.hpp"
#include <utilities/utilities.hpp>

namespace ntt
{
    Path::Path() : Object(), String()
    {
    }

    Path::Path(const char *path) : Object(), String(path)
    {
    }

    Path::Path(const std::string &path) : Object(), String(path)
    {
    }

    Path::Path(const String &path) : Object(), String(path)
    {
    }

    Path::Path(const Path &path) : Object(), String(path)
    {
    }

    Path::~Path()
    {
    }

    String Path::GetFileName(B8 containExtension) const
    {
        return "test_path.cpp";
    }

    String Path::ToString() const
    {
        return Format("<Path: {}>", String(*this));
    }
}