#include "object.hpp"

namespace ntt
{
    Object::Object()
    {
    }

    Object::Object(const Object &)
    {
    }

    Object::~Object()
    {
    }

    String Object::ToString() const
    {
        return "<Object />";
    }
} // namespace ntt
