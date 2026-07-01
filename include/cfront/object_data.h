#include <stdint.h>

#ifndef OPENCF___CFRONT___OBJECT_DATA_H
#define OPENCF___CFRONT___OBJECT_DATA_H

    /**
     * @file include/cfront/object_data.h
     * @brief Macros for declaring data constants and objects in a dedicated section.
     *
     * This header provides helper macros to place constant values and C++ objects
     * into a dedicated data section. It supports typed constants, string literals,
     * C++ container objects, optional type inference helpers, and restricted-mode
     * logic prevention macros. All macros preserve existing declaration behavior.
     */

    /**
     * @def DATA_SEC
     * @brief Attribute to place a variable in the .cdata_space section.
     */
    #define DATA_SEC __attribute__((section(".cdata_space")))

    /**
     * @def cbool
     * @brief Declare a boolean constant in the object data section.
     * @param name identifier.
     * @param val boolean value.
     */
    #define cbool(name, val) const _Bool name DATA_SEC = val;

    /**
     * @def cchar
     * @brief Declare an 8-bit signed char constant in the object data section.
     * @param name identifier.
     * @param val char value.
     */
    #define cchar(name, val) const char name DATA_SEC = val;

    /**
     * @def cshort
     * @brief Declare a 16-bit signed integer constant in the object data section.
     * @param name identifier.
     * @param val short value.
     */
    #define cshort(name, val) const short name DATA_SEC = val;

    /**
     * @def cint
     * @brief Declare a 32-bit signed integer constant in the object data section.
     * @param name identifier.
     * @param val int value.
     */
    #define cint(name, val) const int name DATA_SEC = val;

    /**
     * @def cfloat
     * @brief Declare a float constant in the object data section.
     * @param name identifier.
     * @param val float value.
     */
    #define cfloat(name, val) const float name DATA_SEC = val;

    /**
     * @def cdouble
     * @brief Declare a double constant in the object data section.
     * @param name identifier.
     * @param val double value.
     */
    #define cdouble(name, val) const double name DATA_SEC = val;

    /**
     * @def clong
     * @brief Declare a long integer constant in the object data section.
     * @param name identifier.
     * @param val long value.
     */
    #define clong(name, val) const long name DATA_SEC = val;

    /**
     * @def cint8
     * @brief Declare an 8-bit signed integer constant in the object data section.
     * @param name identifier.
     * @param val int8_t value.
     */
    #define cint8(name, val) const int8_t name DATA_SEC = val;

    /**
     * @def cint16
     * @brief Declare a 16-bit signed integer constant in the object data section.
     * @param name identifier.
     * @param val int16_t value.
     */
    #define cint16(name, val) const int16_t name DATA_SEC = val;

    /**
     * @def cint32
     * @brief Declare a 32-bit signed integer constant in the object data section.
     * @param name identifier.
     * @param val int32_t value.
     */
    #define cint32(name, val) const int32_t name DATA_SEC = val;

    /**
     * @def cuint8
     * @brief Declare an 8-bit unsigned integer constant in the object data section.
     * @param name identifier.
     * @param val uint8_t value.
     */
    #define cuint8(name, val) const uint8_t name DATA_SEC = val;

    /**
     * @def cuint16
     * @brief Declare a 16-bit unsigned integer constant in the object data section.
     * @param name identifier.
     * @param val uint16_t value.
     */
    #define cuint16(name, val) const uint16_t name DATA_SEC = val;

    /**
     * @def cuint32
     * @brief Declare a 32-bit unsigned integer constant in the object data section.
     * @param name identifier.
     * @param val uint32_t value.
     */
    #define cuint32(name, val) const uint32_t name DATA_SEC = val;

    /**
     * @def cstring
     * @brief Declare a string literal constant in the object data section.
     * @param name identifier.
     * @param val string initializer.
     */
    #define cstring(name, val) const char name[] DATA_SEC = val;

    #ifdef __cplusplus

        // for maps and vector and string and functions and queue
        #include <string>
        #include <functional>
        #include <vector>
        #include <queue>
        #include <map>
        #include <unordered_map>
        #include <initializer_list>

        /**
         * @def cxxstring
         * @brief Declare a C++ std::string object in the object data section.
         * @param name identifier.
         * @param val std::string initializer.
         */
        #define cxxstring(name, val) const std::string name DATA_SEC = val;

        /**
         * @def cxxvector
         * @brief Declare a C++ std::vector object in the object data section.
         * @param name identifier.
         * @param type element type.
         * @param ... initializer values.
         */
        #define cxxvector(name, type, ...) const std::vector<type> name DATA_SEC = {__VA_ARGS__};

        /**
         * @def cxxmap
         * @brief Declare a C++ std::map object in the object data section.
         * @param name identifier.
         * @param key_type map key type.
         * @param value_type map value type.
         * @param ... initializer entries.
         */
        #define cxxmap(name, key_type, value_type, ...) const std::map<key_type, value_type> name DATA_SEC = {__VA_ARGS__};

        /**
         * @def cxxunordered_map
         * @brief Declare a C++ std::unordered_map object in the object data section.
         * @param name identifier.
         * @param key_type map key type.
         * @param value_type map value type.
         * @param ... initializer entries.
         */
        #define cxxunordered_map(name, key_type, value_type, ...) const std::unordered_map<key_type, value_type> name DATA_SEC = {__VA_ARGS__};

        /**
         * @def cxxqueue
         * @brief Declare a C++ std::queue object in the object data section.
         * @param name identifier.
         * @param type queue element type.
         */
        #define cxxqueue(name, type) const std::queue<type> name DATA_SEC = std::queue<type>();

        /**
         * @def cxxfunction
         * @brief Declare a C++ std::function object in the object data section.
         * @param name identifier.
         * @param signature function signature.
         * @param func_obj function object initializer.
         */
        #define cxxfunction(name, signature, func_obj) const std::function<signature> name DATA_SEC = func_obj;

        /**
         * @def cxxdata
         * @brief Declare a generic typed object in the object data section.
         * @param name identifier.
         * @param type object type.
         * @param val initializer value.
         */
        #define cxxdata(name, type, val) const type name DATA_SEC = val;

    #endif // __cplusplus

    #ifndef STRICT_MODE

    /**
     * @def cauto
     * @brief Declare a constant with automatic type inference in non-strict mode.
     * @param name identifier.
     * @param val initializer value.
     */
    #define cauto(name, val) const auto name = val;

    /**
     * @def cdynamic
     * @brief Declare a constant with compiler type inference using __typeof__.
     * @param name identifier.
     * @param val initializer value.
     */
    #define cdynamic(name, val) const __typeof__(val) name = val;

    #endif // STRICT_MODE

    #if defined(_WIN64)

    /**
     * @def cint64
     * @brief Declare a 64-bit signed integer constant with 8-byte alignment on Windows.
     * @param name identifier.
     * @param val int64_t value.
     */
    #define cint64(name, val) const int64_t name __attribute__((aligned(8))) = val;

    /**
     * @def cuint64
     * @brief Declare a 64-bit unsigned integer constant with 8-byte alignment on Windows.
     * @param name identifier.
     * @param val uint64_t value.
     */
    #define cuint64(name, val) const uint64_t name __attribute__((aligned(8))) = val;

    #endif // _WIN64

    /**
     * @def carray_i32
     * @brief Declare an array of 32-bit integers.
     * @param name identifier.
     * @param ... initializer values.
     */
    #define carray_i32(name, ...) const int32_t name[] = {__VA_ARGS__};

    /**
     * @def carray_f64
     * @brief Declare an array of double precision floats.
     * @param name identifier.
     * @param ... initializer values.
     */
    #define carray_f64(name, ...) const double name[] = {__VA_ARGS__};

    // allows for using in regular libraries without previnting basic language features
    #ifndef ALLOW_LOGIC_MODE

    /**
     * @def void
     * @brief Disable function definitions when logic mode is not allowed.
     */
    #define void ERROR_FUNCTIONS_NOT_ALLOWED

    /**
     * @def if
     * @brief Disable if statements when logic mode is not allowed.
     */
    #define if ERROR_LOGIC_NOT_ALLOWED

    /**
     * @def for
     * @brief Disable for loops when logic mode is not allowed.
     */
    #define for ERROR_LOGIC_NOT_ALLOWED

    /**
     * @def do
     * @brief Disable do loops when logic mode is not allowed.
     */
    #define do ERROR_LOGIC_NOT_ALLOWED

    /**
     * @def switch
     * @brief Disable switch statements when logic mode is not allowed.
     */
    #define switch ERROR_LOGIC_NOT_ALLOWED

    /**
     * @def while
     * @brief Disable while loops when logic mode is not allowed.
     */
    #define while ERROR_LOGIC_NOT_ALLOWED

    /**
     * @def struct
     * @brief Disable struct definitions when logic mode is not allowed.
     */
    #define struct ERROR_STRUCT_NOT_ALLOWED

    /**
     * @def register
     * @brief Disable register keyword usage when logic mode is not allowed.
     */
    #define register ERROR_NOT_ALLOWED

    /**
     * @def goto
     * @brief Disable goto statements when logic mode is not allowed.
     */
    #define goto ERROR_LOGIC_NOT_ALLOWED

    /**
     * @def typedef
     * @brief Disable typedef definitions when logic mode is not allowed.
     */
    #define typedef ERROR_TYPE_NOT_ALLOWED

    #endif // ALLOW_LOGIC_MODE

#endif // OPENCF___CFRONT___OBJECT_DATA_H