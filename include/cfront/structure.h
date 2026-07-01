#ifndef OPENCF___CFRONT___STRUCTURE_H
#define OPENCF___CFRONT___STRUCTURE_H

    /**
     * @file include/cfront/structure.h
     * @brief Lightweight structural helper macros for C and C++.
     *
     * This header provides shorthand macros for main function entrypoints,
     * loop iteration patterns, conditional jumps, and memory helpers for
     * both C and C++. The macros preserve the original logic and do
     * not alter the underlying behavior.
     */

    /**
     * @def nl_char
     * @brief Newline character constant.
     */
    #define nl_char '\n'

    /**
     * @def tab_char
     * @brief Tab character constant.
     */
    #define tab_char '\t'

    /**
     * @def frontMainExit
     * @brief Define a minimal main function that immediately returns 0.
     */
    #define frontMainExit int main() { return 0; }

    /**
     * @def frontMain
     * @brief Define a main function with argc/argv parameters.
     */
    #define frontMain int main(int argc, char* argv[]) {

    /**
     * @def frontMain
     * @brief Define a main function without parameters.
     */
    #define frontMain int main() {

    /**
     * @def frontRet
     * @brief Return a value from main and close the function body.
     * @param retval return value.
     */
    #define frontRet(retval) return (int)retval; }

    /**
     * @def lessIter
     * @brief Loop macro for iterating from zero to a limit.
     * @param iterator loop variable name.
     * @param value exclusive upper bound.
     */
    #define lessIter(iterator, value) \
        size_t iterator = 0;           \
        iterator < value;              \
        iterator++
    
    /**
     * @def highIter
     * @brief Loop macro for iterating downward from a starting value.
     * @param iterator loop variable name.
     * @param value starting value.
     */
    #define highIter(iterator, value) \
        size_t iterator = value;       \
        iterator >= 0;                 \
        iterator--

    /**
     * @def inRangeIter
     * @brief Loop macro for iterating from a start to end using a custom step.
     * @param iterator loop variable name.
     * @param start initial value.
     * @param end exclusive upper bound.
     * @param step increment step.
     */
    #define inRangeIter(iterator, start, end, step) \
        size_t iterator = start;                    \
        iterator < end;                             \
        iterator += step

    /**
     * @def in_range
     * @brief Compare a value against a min and max using inclusive or exclusive bounds.
     * @param value value to test.
     * @param max upper bound.
     * @param min lower bound.
     * @param symbol '=' for inclusive range, otherwise exclusive.
     */
    #define in_range(value, max, min, symbol)  \
        symbol == '=' ?                        \
        (value) <= (max) && (value) >= (min) : \
        (value) < (max) && (value) > (min)

    /**
     * @def jump
     * @brief Jump to a label using goto.
     * @param label destination label.
     */
    #define jump(label) goto label

    /**
     * @def jump_if
     * @brief Conditionally jump to a label.
     * @param condition condition to evaluate.
     * @param label destination label.
     */
    #define jump_if(condition, label) if(condition) goto label

    /**
     * @def jump_elif
     * @brief Else-if branch used after jump_if.
     * @param condition condition to evaluate.
     * @param label destination label.
     */
    #define jump_elif(condition, label) else if(condition) goto label
    
    /**
     * @def jump_else
     * @brief Else branch used after jump_if.
     * @param label destination label.
     */
    #define jump_else(label) else goto label

    /**
     * @def jump_if_else
     * @brief Jump to one of two labels based on a condition.
     * @param condition condition to evaluate.
     * @param ifLabel label for true branch.
     * @param elseLabel label for false branch.
     */
    #define jump_if_else(condition, ifLabel, elseLabel) \
            if(condition) goto ifLabel;                 \
            else goto elseLabel

    #ifndef __cplusplus

        #include <stdlib.h>

        /**
         * @def front_alloc
         * @brief Allocate an array of type in C.
         * @param type element type.
         * @param size number of elements.
         */
        #define front_alloc(type, size) (type*)malloc(size * sizeof(type))

        /**
         * @def front_realloc
         * @brief Reallocate an existing C array to a new size.
         * @param type element type.
         * @param memory pointer to existing array.
         * @param new_size number of elements in the resized array.
         */
        #define front_realloc(type, memory, new_size) (type*)realloc(memory, new_size * sizeof(type))

        /**
         * @def front_free
         * @brief Free memory allocated with front_alloc in C.
         * @param data pointer to allocated memory.
         */
        #define front_free(data) free(data)

        /**
         * @def object
         * @brief Alias for beginning a struct definition in C.
         */
        #define object typedef struct 

        /**
         * @def cenum
         * @brief Alias for beginning an enum definition in C.
         */
        #define cenum typedef enum

        /**
         * @def cstring
         * @brief Declare a fixed-size character array in C.
         * @param name array identifier.
         * @param sizeValue array length.
         */
        #define cstring(name, sizeValue) char name[sizeValue]

    #endif // __cplusplus

    #ifdef __cplusplus

        /**
         * @def front_alloc
         * @brief Allocate an array of objects in C++.
         * @param type element type.
         * @param size number of elements.
         */
        #define front_alloc(type, size) new type[size]

        /**
         * @def front_realloc
         * @brief Reallocate an array in C++ by allocating a new block and deleting the old one.
         * @param type element type.
         * @param memory pointer to the existing array.
         * @param new_size number of new elements.
         */
        #define front_realloc(type, memory, new_size) \
            type* temp = new type[size];             \
            delete[] memory;                         \
            memory = temp;                           \
            delete temp

        /**
         * @def front_free
         * @brief Free an array allocated with new[] in C++.
         * @param data pointer to allocated array.
         */
        #define front_free(data) delete[] data

        /**
         * @def lambda_func
         * @brief Create a C++ lambda with an explicit return type.
         * @param return_type lambda return type.
         * @param parameters lambda parameter list.
         */
        #define lambda_func(return_type, parameters) parameters -> return_type
        
        /**
         * @def lambda_void
         * @brief Create a C++ lambda with void return.
         * @param parameters lambda parameter list.
         */
        #define lambda_void(parameters) parameters -> void

        #include <string>
        #include <functional>
        #include <vector>
        #include <queue>
        #include <unordered_map>
        #include <initializer_list>

        /**
         * @typedef str
         * @brief Alias for std::string.
         */
        using str = std::string;

        /**
         * @typedef func
         * @brief Alias for std::function<T>.
         */
        template<typename T>
        using func = std::function<T>;

        /**
         * @typedef vec
         * @brief Alias for std::vector<T>.
         */
        template<typename T>
        using vec = std::vector<T>;

        /**
         * @typedef que
         * @brief Alias for std::queue<T>.
         */
        template<typename T>
        using que = std::queue<T>;

        /**
         * @typedef hash_map
         * @brief Alias for std::unordered_map<T, U>.
         */
        template<typename T, typename U>
        using hash_map = std::unordered_map<T, U>;

        /**
         * @typedef initList
         * @brief Alias for std::initializer_list<T>.
         */
        template<typename T>
        using initList = std::initializer_list<T>;

    #endif // __cplusplus

#endif // OPENCF___CFRONT___MICROS_STRUCTURE_H