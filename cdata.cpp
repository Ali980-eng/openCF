// b - for boolean
// c - for char
// i8 - 8 bit signed integer
// i16 or s - 16 bit signed integer or short
// i32 or i - 32 bit signed integer or int
// i64 or l - 64 bit signed integer or long
// ui8 - 8 bit unsigned integer
// ui16 or us - 16 bit unsigned integer or unsigned short
// ui32 or ui - 32 bit unsigned integer or unsigned int
// ui64 or ul - 64 bit unsigned integer or unsigned long
// f - for float
// d - for double
// str - for string

#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> vars;

enum token_type {
    Boolean,
    Character,
    Integer,
    Long,
    Float,
    Double,
    String,
    type_symbol
};