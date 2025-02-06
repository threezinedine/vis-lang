#pragma once
#include "object.hpp"
#include "string.h"
#include <nlohmann/json.hpp>

namespace ntt
{
    /**
     * JavaScript Object Notation (JSON) is a lightweight data-interchange format.
     *      which is wrap of nlohmann::json and provides some more useful and clean
     *      interfaces for this project.
     */
    class Json : public Object
    {
    public:
        Json();
        Json(const String &json);
        virtual ~Json();

#define JSON_GET_METHOD(type) type Get##type(const String &key, type defaultValue) const

        JSON_GET_METHOD(U32);
        JSON_GET_METHOD(U16);
        JSON_GET_METHOD(U8);
        JSON_GET_METHOD(F32);
        JSON_GET_METHOD(F64);
        JSON_GET_METHOD(B8);
        JSON_GET_METHOD(String);

        void operator=(const Json &json);
        String ToString() const override;

    private:
        nlohmann::json m_json;
    };
} // namespace ntt