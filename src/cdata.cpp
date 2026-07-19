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
#include <cinttypes>
#include "cfrost/structure.h"

namespace cdata {
    hash_map<str, bool> booleans;
    hash_map<str, char> chars;
    hash_map<str, int8_t> micro_numbers;
    hash_map<str, int16_t> short_numbers;
    hash_map<str, int32_t> int_numbers;
    hash_map<str, int64_t> long_numbers;
    hash_map<str, uint8_t> umicro_numbers;
    hash_map<str, uint16_t> ushort_numbers;
    hash_map<str, uint32_t> uint_numbers;
    hash_map<str, uint64_t> ulong_numbers;
    hash_map<str, float> float32_numbers;
    hash_map<str, double> float64_numbers;
    hash_map<str, str> strings;
}
