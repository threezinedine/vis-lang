#pragma once
#include <memory>
#include "object.hpp"
#include "allow_types.hpp"
#include "string.hpp"

namespace ntt
{
    // template <typename T>
    // using Scope = std::unique_ptr<T>;

    // template <typename T, typename... Args>
    // constexpr Scope<T> CreateScope(Args &&...args)
    // {
    //     return std::make_unique<T>(std::forward<Args>(args)...);
    // }

    // template <typename T>
    // using Ref = std::shared_ptr<T>;

    // template <typename T, typename... Args>
    // constexpr Ref<T> CreateRef(Args &&...args)
    // {
    //     return std::make_shared<T>(std::forward<Args>(args)...);
    // }

    template <typename T>
    class Scope : public std::unique_ptr<T>, public Object
    {
    public:
        Scope() = default;
        Scope(T *ptr) : std::unique_ptr<T>(ptr) {}
        Scope(std::unique_ptr<T> ptr) : std::unique_ptr<T>(std::move(ptr)) {}

        String ToString() const override
        {
            return Format("<Scope value={} />",
                          ConvertToString(**this));
        }
    };

    template <typename T, typename... Args>
    constexpr Scope<T> CreateScope(Args &&...args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
} // namespace ntt
