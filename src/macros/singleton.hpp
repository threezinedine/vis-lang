#pragma once

/**
 * Used for declaring the the object which has only one instance
 *      during the whole system.
 *
 * @param classType The class type which will be declared as the
 *      singleton object.
 */
#define NTT_SINGLETON_DECLARE(classType) \
private:                                 \
    classType *s_Instance;               \
                                         \
public:                                  \
    static inline void Initialize()      \
    {                                    \
        if (s_Instance == nullptr)       \
        {                                \
            s_Instance = factoryExp;     \
        }                                \
    }                                    \
    static classType *GetSingleton()     \
    {                                    \
        return s_Instance;               \
    }                                    \
    static void Shutdown()               \
    {                                    \
        if (s_Instance != nullptr)       \
        {                                \
            delete s_Instance;           \
            s_Instance = nullptr;        \
        }                                \
    }

/**
 * The implementation of the macro `NTT_SINGLETON_DECLARE`.
 *      This macro must be used in the source file.
 */
#define NTT_SINGLETON_IMPLEMENT(classType) \
    classType *classType::s_Instance = nullptr;
