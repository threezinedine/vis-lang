#include "json.hpp"
#include <string>

namespace ntt
{
    Json::Json()
        : m_json()
    {
    }

    Json::Json(const String &json)
    {
        char *cstr = nullptr;
        U32 length;

        json.ToCharArray(cstr, length);

        m_json = nlohmann::json::parse(cstr);

        delete[] cstr;
    }

    Json::~Json()
    {
    }

#define JSON_GET_METHOD_IMPL(type)                                   \
    type Json::Get##type(const String &key, type defaultValue) const \
    {                                                                \
        char *cstr = nullptr;                                        \
        U32 length;                                                  \
                                                                     \
        key.ToCharArray(cstr, length);                               \
                                                                     \
        if (m_json.contains(cstr))                                   \
        {                                                            \
            type value = m_json[cstr].get<type>();                   \
            delete[] cstr;                                           \
            return value;                                            \
        }                                                            \
        delete[] cstr;                                               \
        return defaultValue;                                         \
    }

    JSON_GET_METHOD_IMPL(U32);
    JSON_GET_METHOD_IMPL(U16);
    JSON_GET_METHOD_IMPL(U8);
    JSON_GET_METHOD_IMPL(F32);
    JSON_GET_METHOD_IMPL(F64);
    JSON_GET_METHOD_IMPL(B8);

    String Json::GetString(const String &key, String defaultValue) const
    {
        char *cstr = nullptr;
        U32 length;

        key.ToCharArray(cstr, length);

        if (m_json.contains(cstr))
        {
            std::string value = m_json[cstr].get<std::string>();
            delete[] cstr;
            return String(value.c_str());
        }
        delete[] cstr;
        return defaultValue;
    }

    void Json::operator=(const Json &json)
    {
        m_json = json.m_json;
    }

    String Json::ToString() const
    {
        return String(m_json.dump(4).c_str());
    }
} // namespace ntt
