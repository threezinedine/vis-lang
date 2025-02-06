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

#define JSON_GET_NUMBER_METHOD_IMPL(type)                            \
    type Json::Get##type(const String &key, type defaultValue) const \
    {                                                                \
        char *cstr = nullptr;                                        \
        U32 length;                                                  \
                                                                     \
        key.ToCharArray(cstr, length);                               \
                                                                     \
        if (m_json.contains(cstr))                                   \
        {                                                            \
            if (m_json[cstr].is_number())                            \
            {                                                        \
                type value = m_json[cstr].get<type>();               \
                delete[] cstr;                                       \
                return value;                                        \
            }                                                        \
            else if (m_json[cstr].is_boolean())                      \
            {                                                        \
                B8 value = m_json[cstr].get<B8>();                   \
                delete[] cstr;                                       \
                return value ? 1 : 0;                                \
            }                                                        \
        }                                                            \
        delete[] cstr;                                               \
        return defaultValue;                                         \
    }

    JSON_GET_NUMBER_METHOD_IMPL(U32);
    JSON_GET_NUMBER_METHOD_IMPL(U16);
    JSON_GET_NUMBER_METHOD_IMPL(U8);
    JSON_GET_NUMBER_METHOD_IMPL(I32);
    JSON_GET_NUMBER_METHOD_IMPL(I16);
    JSON_GET_NUMBER_METHOD_IMPL(I8);
    JSON_GET_NUMBER_METHOD_IMPL(F32);
    JSON_GET_NUMBER_METHOD_IMPL(F64);

    B8 Json::GetB8(const String &key, B8 defaultValue) const
    {
        char *cstr = nullptr;
        U32 length;

        key.ToCharArray(cstr, length);

        if (m_json.contains(cstr))
        {
            if (m_json[cstr].is_boolean())
            {
                B8 value = m_json[cstr].get<B8>();
                delete[] cstr;
                return value;
            }
            else if (m_json[cstr].is_number())
            {
                I32 value = m_json[cstr].get<I32>();
                delete[] cstr;
                return value == 0 ? False : True;
            }
        }
        delete[] cstr;
        return defaultValue;
    }

    String Json::GetString(const String &key, String defaultValue) const
    {
        char *cstr = nullptr;
        U32 length;

        key.ToCharArray(cstr, length);

        if (m_json.contains(cstr) && m_json[cstr].is_string())
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
